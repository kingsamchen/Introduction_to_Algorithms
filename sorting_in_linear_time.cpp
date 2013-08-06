/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/08/06
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

// elements still range between 0~k
void InPlaceCountingSort(vector<int>& src, unsigned int k)
{
    // need O(k) extra storage
    vector<int> eleFreq(k+1);

    for (auto it = src.cbegin(); it != src.cend(); ++it)
    {
        ++eleFreq[*it];
    }

    vector<int> accuEleCnt(eleFreq.cbegin(), eleFreq.cend());
    for (unsigned int i = 1U; i < accuEleCnt.size(); ++i)
    {
        accuEleCnt[i] += accuEleCnt[i-1];
    }

    // need n-1 = O(n) swap in worst-case
    int srcSize = src.size();
    for (int i = 0; i < srcSize; ++i)
    {
        while (eleFreq[src[i]] > 0 && i != accuEleCnt[src[i]])
        {
            --eleFreq[src[i]];
            assert(accuEleCnt[src[i]] >= 0 && accuEleCnt[src[i]] <= srcSize);
            std::swap(src[i], src[--accuEleCnt[src[i]]]);
        }
    }
}

// a special variant
// elements are consecutive integer range within [0, size)
void _InPlaceCountingSort(vector<int>& numbers) 
{
    int size = numbers.size();
    for (int i = 0; i < size; i++ ) 
    {
        while (numbers[i] != i) 
        {
            int temp = numbers[numbers[i]];
            numbers[numbers[i]] = numbers[i];
            numbers[i] = temp;
        }
    }
}