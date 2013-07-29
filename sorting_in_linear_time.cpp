/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/07/29
** Purpose:	chapter 8 implementation
************************************/

#include <vector>

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