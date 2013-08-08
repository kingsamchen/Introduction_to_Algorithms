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

int RandomizedSelect(int ary[], int l, int r, int k);
int RandomizedSelectIter(int ary[], size_t len, int k);

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
    int ary[] = {3,5,2,7,6,10,8};
    //vector<int> v(ary, ary + _countof(ary));
    for (int i = 1; i <= _countof(ary); ++i)
    {
        cout<<RandomizedSelectIter(ary, _countof(ary), i)<<endl;
    }

	_getch();
	return 0;
}