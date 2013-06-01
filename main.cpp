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

void MaxHeapify(int ary[], size_t len, size_t idx);
void MaxHeapify_Iter(int ary[], size_t len, size_t idx);
void BuildHeap(int ary[], size_t len);
void Heapsort(int ary[], size_t len);

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
    int ary[] = {4,1,3,2,16,9,10,14,8,7};
    Heapsort(ary, _countof(ary));
    print_out(ary, ary + _countof(ary));
	_getch();
	return 0;
}

