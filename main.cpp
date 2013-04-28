/************************************
** Edition:	v1.0.0 Demo
** Author:	Kingsley Chen	
** Date:	2013/04/23
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
    
    const int LEN = 5;
    int ary[LEN] = {3,7,4,2,8};
    set<int> s;
    RandomSample(7, 25, s);
    print_out(s.begin(), s.end());
	_getch();
	return 0;
}

