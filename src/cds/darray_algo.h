#ifndef _DArray_algo_h
#define _DArray_algo_h

#include "darray.h"
#include <stdlib.h>
#include <assert.h>
#include "./dbg.h"

typedef int (*compare)(void*, void*);

void DArray_qsort(DArray* darray, compare);

void DArray_qsort_r(DArray* darray, int start, int end, compare);

static void qsort_swap(void** a, void** b);

static int qsort_partition(DArray* darray, int start, int end, compare cmp);



#endif // _DArray_algo_h
