// File: eratosthenes.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 2.8.2023
// Compiled: gcc version 11.3.0

#include <math.h>
#include "bitset.h"
#include "eratosthenes.h"

// implementation of sieve of Eratosthenes algorithm
void Eratosthenes(bitset_t arr)
{
    bitset_index_t arr_size = bitset_size(arr);

    bitset_setbit(arr, 0, 1); // 0 is not a prime number
    bitset_setbit(arr, 1, 1); // 1 is not a prime number

    for(bitset_index_t i = 2; i < sqrt(arr_size); i++)
    {
        if(!bitset_getbit(arr, i))
        {
            for(bitset_index_t j = 2 * i; j < arr_size; j += i)
            {
                bitset_setbit(arr, j, 1);
            }
        }
    }

}