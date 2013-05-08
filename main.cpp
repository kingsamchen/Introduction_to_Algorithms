/************************************
** Edition:	v1.0.0 Demo
** Author:	Kingsley Chen	
** Date:	2013/05/08
** Purpose:	main
************************************/

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>
#include <set>

int RandEx(int a, int b);
void PermutingBySorting(int ary[], size_t len);
void PermutingInPlace(int ary[], size_t len);
void RandomSample(int m, int n, std::set<int>& intSet);
int RandSearch(const int ary[], size_t len, int x);

template<typename T>
void print_out(T beg, T end, const char* dem = " ")
{
    for (auto it = beg; it != end; ++it)
    {
        std::cout<<*it<<dem;
    }

    std::cout<<std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
    using namespace std;
    
    //const int LEN;
    int ary[] = {3,7,4,2,8,12,32,43,34,28,5};
    //cout<<RandSearch(ary, _countof(ary), 28);
	_getch();
	return 0;
}

