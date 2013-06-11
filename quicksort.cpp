/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/06/11
** Purpose:	chapter 7 implementation
************************************/

#include <algorithm>
#include <random>

using std::swap;
using std::random_device;
using std::uniform_int_distribution;
using std::default_random_engine;

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


int RandomPartition(int ary[], int l, int r)
{
    random_device rd;
    default_random_engine rndEngine(rd());
    uniform_int_distribution<unsigned int> uniRnd(l, r);

    int rndIdx = uniRnd(rndEngine);
    swap(ary[r], ary[rndIdx]);

    return Partition(ary, l, r);
}


void QuickSort(int ary[], int l, int r)
{
    if (l < r)
    {
        int pivIdx = RandomPartition(ary, l, r);
        QuickSort(ary, l, pivIdx - 1);
        QuickSort(ary, pivIdx + 1, r);
    }
}


void insertion_sort(int ary[], int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int tmp = ary[i];
        int j = i - 1;
        while (left <= j && tmp < ary[j])
        {
            ary[j+1] = ary[j];
            --j;
        }
        ary[j+1] = tmp;
    }
}


void QSortWithInsertion(int ary[], int l, int r)
{
    const int THRESHOLD = 20;

    if (l < r)
    {
        if (r - l <= THRESHOLD)
        {
            insertion_sort(ary, l, r);
        } 
        else
        {
            int pivIdx = RandomPartition(ary, l, r);
            QSortWithInsertion(ary, l, pivIdx - 1);
            QSortWithInsertion(ary, pivIdx + 1, r);
        }
    }
}