/************************************
** Edition:	v1.0.0 Demo
** Author:	Kingsley Chen	
** Date:	2013/04/23
** Purpose:	chapter 5 implementaion
************************************/

#include <cstdlib>

// assuming returns 0 and 1 equally
inline int RandBase()
{
    return rand() % 2;
}

// omit range checking, assume a and b both are positive integers
int RandEx(int a, int b)
{
    int diff = b - a;
    int bitLen;
    __asm
    {
        xor eax, eax
        bsr eax, diff
        inc eax
        mov bitLen, eax
    }

    int rndInt;
    do 
    {
        rndInt = 0;
        for (int i = 1; i <= bitLen; ++i)
        {
            rndInt = (rndInt << 1) + RandBase();
        }
    } while (rndInt > diff);
 
    return rndInt + a;
}
