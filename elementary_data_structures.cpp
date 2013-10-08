/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/10/08
** Purpose:	Chapter 10 implementations
************************************/

#include <stdexcept>
#include <cassert>
#include <iostream>

// a minimal implementation
// preassume element type is int
class Deque
{
	public:
        Deque() : _data(new int[INIT_SIZE]), _head(0), _tail(0), _capc(INIT_SIZE)
        {}

        ~Deque()
        {
            delete [] _data;
        }

        // omit copy-constructor and copy-assignment

        bool empty()
        {
            return _head == _tail;
        }

        void push_front(int ele)
        {
            if (full())
            {
                // deque is full, expansion code is omitted
            }

            _head = _head == 0 ? _capc - 1 : _head - 1;

            _data[_head] = ele;
        }

        void push_back(int ele)
        {
            if (full())
            {
                // ommit expansion
            }

            _data[_tail] = ele;

            _tail = _tail + 1 == _capc ? 0 : _tail + 1;
        }

        int pop_front()
        {
            if (empty())
            {
                throw std::underflow_error("deque is empty!");
            }

            int ele = _data[_head];
            _head = _head + 1 == _capc ? 0 : _head + 1;

            return ele;
        }

        int pop_back()
        {
            if (empty())
            {
                throw std::underflow_error("deque is empty!");
            }

            int ele = _data[_tail];
            _tail = _tail == 0 ? _capc - 1 : _tail - 1;

            return ele;            
        }

    private:
        bool full()
        {
            return _head == (_tail + 1) % _capc;
        }
            
	private:
        enum {INIT_SIZE = 64}; 
        int* _data;
        int _capc;
        int _head;
        int _tail;
};

struct node
{
    node(int data, node* next = nullptr) : _data(data), _next(next)
    {}

    int _data;
    node* _next;
};

node* InitializeSinglyLinkedList()
{
    node* sentinel = new node(0xDEADBEEF);
    sentinel->_next = sentinel;

    return sentinel;
}

node* SinglyLinkedListInsert(node* lst, int ele)
{
    node* newHead = new node(ele, lst->_next);
    lst->_next = newHead;

    return newHead;
}

void DestroySinglyLinkedList(node*& lst)
{
    for (node* curr = lst->_next; curr != lst;)
    {
        node* next = curr->_next;
        delete curr;
        curr = next;
    }

    delete lst;
    lst = nullptr;
}

/*
  brief:
    reverse a singly linked list that employs sentinel strategy
    code might be more succint if no sentinal used
  param:
    lst[in] - pointer to sentinel node of the linked list
  return:
    none
*/
void ReverseSinglyLinkedList(node* lst)
{
    node* prev = lst;
    node* curr = lst->_next;
    while (curr != lst)
    {
        node* next = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = next;
    }

    lst->_next = prev;
}

class XORQueue
{
    public:
        XORQueue() : _head(0), _tail(0)
        {
        }

        ~XORQueue()
        {
            Destroy();
        }

        /* omit copy-counterparts */

        void Enqueue(int ele)
        {
            node* entry = new node();
            entry->data = ele;

            if (!_head)
            {
                entry->prevNextAddr = 0;
                _head = entry;
            }
            else if (!_tail)
            {
                entry->prevNextAddr = _head;
                _tail = entry;
                _head->prevNextAddr = _tail;
            } 
            else
            {
                entry->prevNextAddr = _tail;
                _tail->prevNextAddr = (node*)((int)(_tail->prevNextAddr) ^ (int)(entry));
                _tail = entry;
            }
        }

        int Dequeue()
        {
            assert(_head != 0);
            int data = _head->data;

            if (!_tail)
            {
                delete _head;
                _head = 0;

                return data;    
            }
            else if (_head->prevNextAddr == _tail && _tail->prevNextAddr == _head)
            {
                delete _head;
                _head = _tail;
                _tail = 0;
                _head->prevNextAddr = 0;

                return data;
            }
            else
            {
                node* tmp = _head;
                _head = _head->prevNextAddr;
                _head->prevNextAddr = (node*)((int)(_head->prevNextAddr) ^ (int)(tmp));
                delete tmp;

                return data;
            }
        }
    
        int empty()
        {
            return _head == 0;
        }

    private:
        void Destroy()
        {
            node* prev = 0;
            node* curr = _head;

            while (prev != _tail)
            {
                node* next = (node*)((int)curr->prevNextAddr ^ (int)prev);
                delete curr;
                prev = curr;
                curr = next;
            }
        }

    private:
        struct node
        {
            int data;
            node* prevNextAddr;
        };

        node* _head;
        node* _tail;
};

/* Test-Driven Interface */
void DoTest()
{
    XORQueue xorLst;
    xorLst.Enqueue(1);
    xorLst.Enqueue(3);
    xorLst.Enqueue(5);
    xorLst.Enqueue(7);
    
    std::cout<<xorLst.Dequeue()<<std::endl;
    std::cout<<xorLst.Dequeue()<<std::endl;    
}