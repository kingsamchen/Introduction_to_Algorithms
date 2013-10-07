/************************************
** Edition:	Demo
** Author:	Kingsley Chen	
** Date:	2013/10/07
** Purpose:	Chapter 10 implementations
************************************/

#include <stdexcept>

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