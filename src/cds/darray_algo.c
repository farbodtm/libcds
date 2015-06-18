#include "darray_algo.h"
#include "darray.h"

// general quicksort function
void DArray_qsort(DArray* darray, compare cmp) {
  DArray_qsort_r(darray, 0, (darray->end), cmp);
}

// quicksort 
void DArray_qsort_r(DArray* darray, int start, int end, compare cmp) {
  int pivot;
  if (start < end) {
    pivot = qsort_partition(darray, start, end, cmp);
    DArray_qsort_r(darray, start, pivot - 1, cmp);
    DArray_qsort_r(darray, pivot + 1, end, cmp);
  }
}

static void qsort_swap(void** a, void** b) {
  void* tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

static int qsort_partition(DArray* darray, int start, int end, compare cmp) {
  void* r = darray->contents[end];
  int i = start - 1, j;
  for(j = start; j < end; j++) {
    if ( cmp(darray->contents[j],r) ) {
      i++;
      qsort_swap(&(darray->contents[i]), &(darray->contents[j]));
    }
  }
  qsort_swap(darray->contents[i+1], darray->contents[end]);
  return i+1;
}
