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
#include <cassert>

struct node
{
    node(int data, node* next = nullptr) : _data(data), _next(next)
    {}

    int _data;
    node* _next;
};

node* InitializeSinglyLinkedList();
node* SinglyLinkedListInsert(node* lst, int ele);
void DestroySinglyLinkedList(node*& lst);
void ReverseSinglyLinkedList(node* lst);

using namespace std;

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
    //int ary[] = {4,7,4,2,1,9,8};
    node* lst = InitializeSinglyLinkedList();
    SinglyLinkedListInsert(lst, 1);
    SinglyLinkedListInsert(lst, 3);
    SinglyLinkedListInsert(lst, 5);
    ReverseSinglyLinkedList(lst);

    node* p = lst->_next;
    while (p != lst)
    {
        cout<<"node "<<p->_data<<endl;
        p = p->_next;
    }
    DestroySinglyLinkedList(lst);
    assert(lst == nullptr);
	_getch();
	return 0;
}