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
#include <vector>

using namespace std;

void CountingSort(vector<int>& src, unsigned int k);

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
    int ary[] = {4,1,3,4,3};
    vector<int> v(ary, ary + 5);
    CountingSort(v, 4);
    print_out(v.cbegin(), v.cend());
	_getch();
	return 0;
}

