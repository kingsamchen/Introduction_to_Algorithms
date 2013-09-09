/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/09/09
** Purpose:	chapter 9 implementation
************************************/

#include <algorithm>
#include <xutility>
#include <random>
#include <cassert>
#include <vector>

using std::swap;
using std::random_device;
using std::uniform_int_distribution;
using std::default_random_engine;
using std::vector;
using std::min;

typedef std::pair<int,int> MaxMinPair;
int RandomPartition(int ary[], int l, int r);

// less than 3n/2 times of comparisons
MaxMinPair FindLargestSmallestPair(const int* ary, size_t len)
{
    int tmpMax, tmpMin;
    unsigned int begPos = 0U;
    if (len & 1)
    {
        tmpMin = tmpMax = ary[0];
        begPos = 1U;
    } 
    else
    {
        tmpMax = std::max(ary[0], ary[1]);
        tmpMin = std::min(ary[0], ary[1]);
        begPos = 2U;
    }

    for (unsigned int i = begPos; i < len; i += 2)
    {
        if (ary[i] < ary[i+1])
        {
            tmpMin = std::min(tmpMin, ary[i]);
            tmpMax = std::max(tmpMax, ary[i+1]);
        } 
        else
        {
            tmpMin = std::min(tmpMin, ary[i+1]);
            tmpMax = std::max(tmpMax, ary[i]);
        }
    }

    return std::make_pair<int, int>(tmpMax, tmpMin);
}

// k-th smallest
int RandomizedSelect(int ary[], int l, int r, int k)
{
    if (l == r)
    {
        return ary[l];
    }

    int pi = RandomPartition(ary, l, r);
    int lessEqlCnt = pi - l + 1;

    if (lessEqlCnt == k)
    {
        return ary[pi];
    }
    else if (lessEqlCnt < k)
    {
        return RandomizedSelect(ary, pi + 1, r, k - lessEqlCnt);
    } 
    else
    {
        return RandomizedSelect(ary, l, pi - 1, k);
    }
}

// iterative version
int RandomizedSelectIter(int ary[], size_t len, int k)
{
    assert(k >= 1 && k <= static_cast<int>(len));
    int l = 0, r = len - 1;
    int index = -1;
    while (l <= r)
    {
        int s = RandomPartition(ary, l, r);
        if (s + 1 == k)
        {
            index = s;
            break;
        }
        else if (s + 1 < k)
        {
            l = s + 1;
        } 
        else
        {
            r = s - 1;
        }
    }

    assert(index != -1);
    return ary[index];
}

// return the double of the median found in the ary for consistency 
inline int GetPreMedian(const int* ary, int l, int r)
{
    int m = l + ((r - l) >> 1);
    return ((r - l + 1) & 1) ? 2 * ary[m] : ary[m] + ary[m+1];
}

double FindMedian(const int* a1, const int* a2, int count)
{
    int left1, right1, left2, right2;
    left1 = left2 = 0;
    right1 = right2 = count - 1;

    /* right1 - left1 == right2 - left2 */
    while (right1 - left1 > 1)
    {
        int m1 = GetPreMedian(a1, left1, right1);
        int m2 = GetPreMedian(a2, left2, right2);
        int mid1 = left1 + ((right1 - left1) >> 1);
        int mid2 = left2 + ((right2 - left2) >> 1);

        if (m1 == m2)
        {
            return static_cast<double>(m1) / 2;
        }
        else if (m1 < m2)   /* m1 <= M <= a1[r] or a2[l] <= M <= m2 */
        {
            left1 = mid1;
            if ((right2 - left2 + 1) & 1)   // odd
            {
                right2 = mid2;
            }
            else    // even
            {
                right2 = mid2 + 1;  
            }   
        }
        else
        {
            left2 = mid2;
            if ((right1 - left1 + 1) & 1)
            {
                right1 = mid1;
            }
            else
            {
                right1 = mid1 + 1;
            }
        }
    }

    // for two arrays below, each owns two elements repectively
    int l = left1, r = left2;
    int m = 0;
    for (int i = 1; i <= 3; ++i)
    {
        if (a1[l] < a2[r])
        {
            m += (2 == i || 3 == i) ? a1[l] : 0;
            ++l;
        }
        else
        {
            m += (2 == i || 3 == i) ? a2[r] : 0;
            ++r;
        }
    }

    return static_cast<double>(m) / 2;
}

int Find2ndSmallest(const int* src, int len)
{
    // total need 2*len-1 cells for placing
    vector<int> tour((len << 1) - 1);
    std::copy(src, src + len, &tour[len-1]);

    // tournamently compare
    for (int i = len * 2 - 2; i > 0; i -= 2)
    {
        tour[i/2-1] = min(tour[i], tour[i-1]);
    }

    int minEle = tour.front();
    int secndMin = INT_MAX;
    for (int i = 0; i < len - 1;)
    {
        if (tour[(i + 1) * 2] == minEle)
        {
            i = (i + 1) * 2;
            secndMin = min(secndMin, tour[i-1]);
        } 
        else
        {
            i = i * 2 + 1;
            secndMin = min(secndMin, tour[i+1]);
        }
    }

    return secndMin;
}