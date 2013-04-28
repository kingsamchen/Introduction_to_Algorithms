/************************************
** Edition:	v1.0.0 Demo
** Author:	Kingsley Chen	
** Date:	2013/04/28
** Purpose:	chapter 5 implementaion
************************************/

#include <cstdlib>
#include <vector>
#include <ctime>
#include <set>

using std::size_t;
using std::vector;
using std::set;

// assuming returns 0 and 1 equally
inline int RandBase()
{
    return rand() % 2;
}

// omit range checking, assume a and b both are positive integers
int RandEx(int a, int b)
{
    int diff = b - a;
    int bitLen;
    __asm
    {
        xor eax, eax
        bsr eax, diff
        inc eax
        mov bitLen, eax
    }

    int rndInt;
    do 
    {
        rndInt = 0;
        for (int i = 1; i <= bitLen; ++i)
        {
            rndInt = (rndInt << 1) + RandBase();
        }
    } while (rndInt > diff);
 
    return rndInt + a;
}


int Partition(int a[], vector<unsigned>& prio, int left, int right)
{
	// pick the pivot from median of the three
	int mid = (left + right) >> 1;
	if (prio[left] > prio[mid])
	{
		std::swap(a[left], a[mid]);
        std::swap(prio[left], prio[mid]);
	}
	if (prio[mid]> prio[right])
	{
		std::swap(a[mid], a[right]);
		std::swap(prio[mid], prio[right]);
	}
	if (prio[left] > prio[mid])
	{
		std::swap(a[left], a[mid]);
		std::swap(prio[left], prio[mid]);
	}

	/* {prio[left] <= prio[mid] <= prio[right]} */
	std::swap(prio[mid], prio[right-1]);
    std::swap(a[mid], a[right-1]);
	unsigned int pivot = prio[right-1];

	int l = left;
	int r = right - 1;

	do 
	{
		while (prio[++l] < pivot)
		{
		}
		while (prio[--r] > pivot)
		{
		}

		if (l < r)
		{
			std::swap(a[l], a[r]);
            std::swap(prio[l], prio[r]);
		}

	} while (l < r);

	std::swap(a[l], a[right-1]);
	std::swap(prio[l], prio[right-1]);
	return l;
}

void SortviaPriority(int ary[], vector<unsigned>& prio, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    else if (low + 1 == high)
    {
        if (prio[low] > prio[high])
        {
            std::swap(ary[low], ary[high]);
            std::swap(prio[low], prio[high]);
        }
    }
    else
    {
        int pivot = Partition(ary, prio, low, high);
        SortviaPriority(ary, prio, low, pivot - 1);
        SortviaPriority(ary, prio, pivot + 1, high);
    }
}

void PermutingBySorting(int ary[], size_t len)
{
    vector<unsigned int> prior;
    prior.reserve(len);
    srand(static_cast<unsigned int>(time(nullptr)));

    for (size_t i = 0; i < len; ++i)
    {
        unsigned int maxPriorValue = len * len * len;
        // geenrate priority ranging from 1 to n^3, both inclusive
        // priorUpper may even bigger than RAND_MAX, but this case is ignored
        prior.push_back(static_cast<unsigned>(rand() % maxPriorValue + 1));
    }

    SortviaPriority(ary, prior, 0, len - 1);
}


void PermutingInPlace(int ary[], size_t len)
{
    srand(static_cast<unsigned>(time(nullptr)));
    for (size_t i = 0; i < len; ++i)
    {
        // i <= rndIdx <= len-1
        size_t rndIdx = rand() % (len - i) + i;
        std::swap(ary[i], ary[rndIdx]);
    }
}


// can be implemented in an iterative version
void RandomSample(int m, int n, set<int>& intSet)
{
    if (m == 0)
    {
        return;
    } 
    else
    {
        RandomSample(m-1, n-1, intSet);
        
        // ele in [1,n]
        int ele = rand() % n + 1;
        if (intSet.find(ele) == intSet.end())
        {
            intSet.insert(ele);
        } 
        else
        {
            intSet.insert(n);
        }
    }
}