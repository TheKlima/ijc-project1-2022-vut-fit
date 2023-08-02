// File: ppm.c
// Subject: IJC
// Project: #1
// Author: Andrii Klymenko, FIT VUT
// Login: xklyme00
// Date: 2.8.2023
// Compiled: gcc version 11.3.0

#include <stdlib.h>
#include <stdio.h>
#include "ppm.h"
#include "error.h"

#define MAX_WIDTH 8000 // maximal with of the PPM image
#define MAX_HEIGHT MAX_WIDTH // maximal height of the PPM image

// loads the contents of the PPM file with name 'filename' into dynamically allocated structure 'ppm'
struct ppm *ppm_read(const char *filename)
{
    FILE *fp = fopen(filename, "r");

    if(fp == NULL)
    {
        warning_msg("Couldn't open a file with a name '%s'\n", filename);
        return NULL;
    }

    unsigned x_size, y_size;

    if((fscanf(fp, "P6\n%u %u\n255\n", &x_size, &y_size)) != 2)
    {
        warning_msg("File '%s' has a wrong format\n", filename);
        fclose(fp);
        return NULL;
    }

    if(x_size > MAX_WIDTH || y_size > MAX_HEIGHT)
    {
        warning_msg("File '%s' has invalid width/height\n", filename);
        fclose(fp);
        return NULL;
    }

    int char_number = 3 * x_size * y_size;
    struct ppm *ppm = (struct ppm*) malloc(sizeof(struct ppm) + char_number);

    if(ppm == NULL)
    {
        warning_msg("Couldn't allocate memory for 'ppm' structure\n");
        fclose(fp);
        return NULL;
    }

    ppm->xsize = x_size;
    ppm->ysize = y_size;

    int i = 0;
    int c;

    while((c = getc(fp)) != EOF)
    {
        ppm->data[i++] = c;

        if(i > char_number)
            break;
    }

    if(i != char_number)
    {
        warning_msg("Size of PPM file '%s' specified in this file differs from its actual size\n", filename);
        fclose(fp);
        ppm_free(ppm);
        return NULL;
    }
    
    fclose(fp);
    return ppm;
}

// frees dynamically allocated memory for a ppm structure in the 'ppm_read' function
void ppm_free(struct ppm *p)
{
    if(p != NULL)
    {
        free(p);
        p = NULL;
    }
}
