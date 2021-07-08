/* vim: set tabstop=4 expandtab shiftwidth=4 softtabstop=4: */

/*
 * Copyright 2015 University of Piemonte Orientale, Computer Science Institute
 *
 * This file is part of UPOalglib.
 *
 * UPOalglib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * UPOalglib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with UPOalglib.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <assert.h>
#include "sort_private.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void upo_swap(void *a, void *b, size_t size)
{
    unsigned char *aa = a, *bb = b, tmp;
    for (size_t i = 0; i < size; ++i)
    {
        tmp = aa[i];
        aa[i] = bb[i];
        bb[i] = tmp;
    }
}

void upo_bubble_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    unsigned char *array = base;
    int k = 1;

    while (k == 1)
    {
        k = 0;
        for (size_t i = 0; i < n - 1; i++)
            if (cmp(array + i * size, array + (i + 1) * size) > 0)
            {
                upo_swap(array + i * size, array + (i + 1) * size, size);
                k = 1;
            }
    };
}

void upo_insertion_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    unsigned char *basePtr = base;
    for (size_t i = 0; i < n; i++)
    {
        size_t j = i;
        while (j > 0 && cmp(basePtr + j * size, basePtr + (j - 1) * size) < 0)
        {
            upo_swap(basePtr + j * size, basePtr + (j - 1) * size, size);
            j -= 1;
        }
    }
}

void upo_merge_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    upo_merge_sort_rec(base, 0, n - 1, size, cmp);
}

void upo_merge_sort_rec(void *base, size_t lo, size_t hi, size_t size, upo_sort_comparator_t cmp)
{
    if (lo >= hi)
        return;
    size_t mid = (lo + hi) / 2;
    upo_merge_sort_rec(base, lo, mid, size, cmp);
    upo_merge_sort_rec(base, mid + 1, hi, size, cmp);
    upo_merge(base, lo, mid, hi, size, cmp);
}

void upo_merge(void *base, size_t lo, size_t mid, size_t hi, size_t size, upo_sort_comparator_t cmp)
{
    unsigned char *auxPtr = malloc(size * (hi - lo + 1)), *basePtr = base;
    size_t i = 0, j = mid + 1 - lo;
    // memcpy(auxPtr + lo * size, basePtr + hi * size, size);

    for (size_t l = lo; l <= hi; ++l)
        memcpy(auxPtr + (l - lo) * size, basePtr + l * size, size);

    for (size_t k = lo; k <= hi; ++k)
    {
        if (i > (mid - lo))
        {
            memcpy(basePtr + k * size, auxPtr + j * size, size);
            j++;
        }
        else if (j > (hi - lo))
        {
            memcpy(basePtr + k * size, auxPtr + i * size, size);
            i++;
        }
        else if (cmp(auxPtr + j * size, auxPtr + i * size) < 0)
        {
            memcpy(basePtr + k * size, auxPtr + j * size, size);
            j++;
        }
        else
        {
            memcpy(basePtr + k * size, auxPtr + i * size, size);
            i++;
        }
    }

    free(auxPtr);
}

void upo_quick_sort(void *base, size_t n, size_t size, upo_sort_comparator_t cmp)
{
    upo_quick_sort_rec(base, 0, n - 1, size, cmp);
}

void upo_quick_sort_rec(void *base, size_t lo, size_t hi, size_t size, upo_sort_comparator_t cmp)
{
    if (lo >= hi)
        return;
    size_t j = upo_quick_sort_partition(base, lo, hi, size, cmp);

    if (j > 0)
        upo_quick_sort_rec(base, lo, j - 1, size, cmp);
    upo_quick_sort_rec(base, j + 1, hi, size, cmp);
}

size_t upo_quick_sort_partition(void *base, size_t lo, size_t hi, size_t size, upo_sort_comparator_t cmp)
{
    unsigned char *basePtr = base;
    size_t p = lo, i = lo, j = hi;

    while (i < j)
    {
        while (i < hi && cmp(basePtr + i * size, basePtr + p * size) < 0)
            i++;
        while (j > lo && cmp(basePtr + j * size, basePtr + p * size) > 0)
            j--;
        upo_swap(basePtr + i * size, basePtr + j * size, size);
    }

    upo_swap(basePtr + p * size, basePtr + j * size, size);
    return j;
}