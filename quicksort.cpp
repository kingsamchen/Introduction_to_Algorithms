/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/06/09
** Purpose:	chapter 7 implementation
************************************/

#include <algorithm>

using std::swap;

int Partition(int ary[], int l, int r)
{
    int left = l - 1;
    int pivot = ary[r];

    /* A[l..left] <= pivot < A[left+1..i] */
    for (int i = l; i < r; ++i)
    {
        // replace <= with >= if nondecreasing order is required
        if (ary[i] <= pivot)
        {
            swap(ary[++left], ary[i]);
        }
    }

    swap(ary[++left], ary[r]);
    return left;
}


void QuickSort(int ary[], int l, int r)
{
    if (l < r)
    {
        int pivIdx = Partition(ary, l, r);
        QuickSort(ary, l, pivIdx - 1);
        QuickSort(ary, pivIdx + 1, r);
    }
}