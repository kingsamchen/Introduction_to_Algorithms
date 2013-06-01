/************************************
** Edition:	v1.0.0 Demo
** Author:	Kingsley Chen	
** Date:	2013/06/01
** Purpose:	chapter 6 implementation
************************************/

#include <cstdlib>
#include <algorithm>

#define LEFT(x)     ((x << 1) + 1)
#define RIGHT(x)    ((x + 1) << 1)
#define PARENT(x)   (((x + 1) >> 1) - 1)

using std::swap;

void MaxHeapify(int ary[], size_t len, size_t idx)
{
    size_t lc = LEFT(idx), rc = RIGHT(idx);
    size_t largest;

    if (lc < len && ary[idx] < ary[lc])
    {
        largest = lc;
    } 
    else
    {
        largest = idx;
    }

    if (rc < len && ary[largest] < ary[rc])
    {
        largest = rc;
    }

    if (idx != largest)
    {
        swap(ary[idx], ary[largest]);
        MaxHeapify(ary, len, largest);
    }
}

void MaxHeapify_Iter(int ary[], size_t len, size_t idx)
{
    size_t idxChecking = idx;
    int val = ary[idxChecking];
    bool isHeap = false;

    while (!isHeap && LEFT(idxChecking) < len)
    {
        size_t j = LEFT(idxChecking);
        if (j < len - 1 && ary[j] < ary[j+1])
        {
            // node number idxChecking has two children and we locate
            // at the bigger one
            ++j;
        }

        // float-down check if necessary
        if (val < ary[j])
        {
            ary[idxChecking] = ary[j];
            idxChecking = j;
        }
        else
        {
            isHeap = true;
        }
    }

    ary[idxChecking] = val;
}


void BuildHeap(int ary[], size_t len)
{
    for (int i = PARENT(len-1); i >= 0; --i)
    {
        MaxHeapify_Iter(ary, len, i);
    }
}


void Heapsort(int ary[], size_t len)
{
    BuildHeap(ary, len);
    for (int i = len - 1; i > 0; --i)
    {
        swap(ary[0], ary[i]);
        --len;
        MaxHeapify_Iter(ary, len, 0);
    }
}