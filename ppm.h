// File: ppm.h
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 2.8.2023
// Compiled: gcc version 11.3.0

#ifndef PPM_H
#define PPM_H

struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];    // RGB bytes, int total 3*xsize*ysize
};

struct ppm *ppm_read(const char *filename);

void ppm_free(struct ppm *p);

#endif