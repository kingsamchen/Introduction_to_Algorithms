/************************************
** Edition:	v1.0.0 Demo
** Author:	Kingsley Chen	
** Date:	2013/08/06
** Purpose:	main
************************************/

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include <set>
#include <vector>

using namespace std;

void CountingSort(vector<int>& src, unsigned int k);
void RadixSort(vector<unsigned int>& src);
void BucketSort(vector<double>& src);
void InPlaceCountingSort(vector<int>& src, unsigned int k);

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
    //const int LEN;
    int ary[] = {2,5,3,0,2,3,0,3};
    vector<int> v(ary, ary + _countof(ary));
    InPlaceCountingSort(v, 5);
    print_out(v.cbegin(), v.cend());
	_getch();
	return 0;
}

