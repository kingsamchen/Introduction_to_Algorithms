/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/08/02
** Purpose:	chapter 8 implementation
************************************/

#include <vector>
#include <list>
#include <algorithm>
#include <cassert>

using std::vector;
using std::list;
using std::for_each;

// all elements in src range from 0 to k
void CountingSort(vector<int>& src, unsigned int k)
{
    vector<int> aux(k+1);

    for (auto it = src.cbegin(); it != src.cend(); ++it)
    {
        ++aux[*it];
    }

    for (auto it = aux.begin() + 1; it != aux.end(); ++it)
    {
        *it += *(it - 1);
    }

    vector<int> tmp(src.size());
    for (auto it = src.crbegin(); it != src.crend(); ++it)
    {
        tmp[--aux[*it]] = *it;
    }

    src.swap(tmp);
}

// use counting sort here
void UnderlyingSort(vector<unsigned int>& src, int sectLen, int round)
{
    vector<int> aux(1U << sectLen);

    for (auto it = src.cbegin(); it != src.cend(); ++it)
    {
        int sectVal = ((*it) >> (round * 8)) & 0xFF;
        assert(sectVal >= 0 && sectVal < 256);
        ++aux[sectVal];
    }

    for (auto i = 1U; i < aux.size(); ++i)
    {
        aux[i] += aux[i-1];
    }

    vector<unsigned int> tmp(src.size());
    for (auto it = src.crbegin(); it != src.crend(); ++it)
    {
        int sectVal = ((*it) >> (round * 8)) & 0xFF;
        assert(sectVal >= 0 && sectVal < 256);
        tmp[--aux[sectVal]] = *it;
    }

    src.swap(tmp);
}

// use unsigned int in default thus
// 32-bit r = 8-bit d = 32/8 = 4 rounds
void RadixSort(vector<unsigned int>& src)
{
    const int BIT_LEN = 32;
    const int SECTION_LEN = 8;
    const int ROUND = BIT_LEN / SECTION_LEN;

    for (int i = 0; i < ROUND; ++i)
    {
        UnderlyingSort(src, SECTION_LEN, i);
    }
}

// all elements range from [0, 1)
void BucketSort(vector<double>& src)
{
    vector<list<double>> slots(src.size());

    // insert element into a proper slot
    for (auto it = src.cbegin(); it != src.cend(); ++it)
    {
        int bucket = static_cast<int>(*it * src.size());
        slots[bucket].push_back(*it);
    }

    // sort slots
    for_each(slots.begin(), slots.end(), [=](list<double>& l)
    {
        l.sort();
    });

    src.clear();
    for (auto it = slots.cbegin(); it != slots.cend(); ++it)
    {
        if (!it->empty())
        {
            for (auto ele = it->cbegin(); ele != it->cend(); ++ele)
            {
                src.push_back(*ele);
            }
        }
    }
}