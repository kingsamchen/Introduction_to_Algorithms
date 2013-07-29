/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/06/15
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


std::pair<int, int> EqualPartition(int ary[], int l, int r)
{
    int lt = l;
    int gt = r;

    int pivot = ary[l];
    /* A[i..q-1] < A[q..t] < A[t+1..r] */
    for (int j = l + 1; j <= gt;)
    {
        if (ary[j] < pivot)
        {
            swap(ary[j++], ary[lt++]);
        }
        else if (ary[j] > pivot)
        {
            swap(ary[j], ary[gt--]);
        } 
        else
        {
            ++j;
        }
    }

    return std::make_pair(lt, gt);
}


int Partition_(int a[], int left, int right)
{
    int piv = a[left];
    int l = left, r = right + 1;
 
    do
    {
        do 
        {
            ++l;
        } while (a[l] < piv && l < r);
 
        do 
        {
            --r;
        } while (a[r] > piv);
 
        if (l < r)
        {
            std::swap(a[l], a[r]);
        }
        else
            break;
    }while (l < r);
 
    std::swap(a[left], a[r]);
    return r;
}

 
int Partition_median(int a[], int left, int right)
{
	// pick the pivot from median of the three
	int mid = (left + right) >> 1;
	if (a[left] > a[mid])
	{
		std::swap(a[left], a[mid]);
	}
	if (a[mid]> a[right])
	{
		std::swap(a[mid], a[right]);
	}
	if (a[left] > a[mid])
	{
		std::swap(a[left], a[mid]);
	}
 
	/* {a[left] <= a[mid] <= a[right]} */
	std::swap(a[mid], a[right-1]);
	int pivot = a[right-1];
 
	int l = left;
	int r = right - 1;
 
	do 
	{
		while (a[++l] < pivot)
		{
		}
		while (a[--r] > pivot)
		{
		}
 
		if (l < r)
		{
			std::swap(a[l], a[r]);
		}
 
	} while (l < r);
 
	std::swap(a[l], a[right-1]);
	return l;
}