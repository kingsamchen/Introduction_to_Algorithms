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

int RandEx(int a, int b);

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
    const int LEN = 15;
    int ary[LEN];
    srand(time(nullptr));
    for_each(ary, ary + LEN, [=](int& v)
    {
        v = RandEx(5, 25);
    });
    print_out(ary, ary + LEN);
	_getch();
	return 0;
}

