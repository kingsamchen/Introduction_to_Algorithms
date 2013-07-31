/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/07/31
** Purpose:	chapter 8 implementation
************************************/

#include <vector>
#include <cassert>

using std::vector;

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