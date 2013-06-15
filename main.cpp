/************************************
** Edition:	v1.0.0 Demo
** Author:	Kingsley Chen	
** Date:	2013/06/01
** Purpose:	main
************************************/

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include <set>

int Partition(int ary[], int l, int r);
void QuickSort(int ary[], int l, int r);
void QSortWithInsertion(int ary[], int l, int r);
std::pair<int, int> EqualPartition(int ary[], int l, int r);

template<typename T>
void print_out(T beg, T end, const char* dem = " ")
{
    for (auto it = beg; it != end; ++it)
    {
        std::cout<<*it<<dem;
    }

    std::cout<<std::endl;
}

int _tmain(int, _TCHAR**)
{
    using namespace std;
    
    //const int LEN;
    int ary[] = {4,2,4,1,5,3,7,4};
    pair<int, int>&& range = EqualPartition(ary, 0, _countof(ary) - 1);
    cout<<"range:"<<range.first<<" "<<range.second<<endl;
    print_out(ary, ary + _countof(ary));
	_getch();
	return 0;
}

