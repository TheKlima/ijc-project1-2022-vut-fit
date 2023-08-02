// File: bitset.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 2.8.2023
// Compiled: gcc version 11.3.0

#ifdef USE_INLINE

#include "bitset.h"

// declarations of the inline functions
extern inline void bitset_free(bitset_t bitset);
extern inline bitset_index_t bitset_size(bitset_t bitset);
extern inline void bitset_setbit(bitset_t bitset, bitset_index_t idx, int expr);
extern inline int bitset_getbit(bitset_t bitset, bitset_index_t idx);

#endif