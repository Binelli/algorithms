#include "square-and-multiply.h"
#include <cmath>
#include <iostream>

using namespace std;

int get_leftmost_set_bit(int power)
{
    int mask = 1 << sizeof(int) * 8 - 2;

    int result = sizeof(int) * 8 - 1;
    do
    {
        if ((mask & power) == mask)
        {
            break;
        }
        result--;
        mask = mask >> 1;
    } while (result > 0);

    return result - 1;
}

int square_and_multiply(int base, int power, int mod)
{
    if (power == 0)
    {
        return 1;
    }
    
    int start_pos = get_leftmost_set_bit(power);

    base = base % mod;
    int result = base;

    while (--start_pos >= 0)
    {
        int mask = 1 << start_pos;
        switch (mask & power)
        {
            case 0:
                result *= result;
                result %= mod;
                break;
            default:
                result *= result;
                result %= mod;
                result *= base;
                result %= mod;
            break;
        }
    }

    return result;
}