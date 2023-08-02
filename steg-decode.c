// File: steg-decode.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 2.8.2023
// Compiled: gcc version 11.3.0

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ppm.h"
#include "eratosthenes.h"
#include "bitset.h"
#include "error.h"

#define START_PRIMES 29

int main(int argc, char *argv[])
{
    if(argc != 2)
        error_exit("Program needs only one argument\n");

    struct ppm *ppm = ppm_read(argv[1]);

    if(ppm == NULL)
        error_exit("ppm_read: Couldn't read an image in PPM format\n");

    bitset_index_t arr_size = ppm->xsize * ppm->ysize * 3;
    bitset_alloc(arr, arr_size);

    Eratosthenes(arr);

    char tmp = 0;
    char bit_number = 0;
    bool end = false;

    for(bitset_index_t i = START_PRIMES; i < arr_size; i++)
    {
        if(!bitset_getbit(arr, i))
        {
            tmp |= ((ppm->data[i] & 1) << bit_number);
            bit_number++;

            if(bit_number == 8)
            {
                if(tmp == '\0')
                {
                    end = true;
                    break;
                }

                putchar(tmp);
                bit_number = 0;
                tmp = 0;
            }

        }
    }
    putchar('\n');

    if(!end)
        error_exit("There is no '\\0' character in the end of the 'secret'\n");

    bitset_free(arr);
    ppm_free(ppm);
    return 0;
}

