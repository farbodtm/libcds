#include "minunit.h"
#include "../src/cds/darray.h"
#include "../src/cds/darray_algo.h"

static DArray *array = NULL;
static int *val1 = NULL;
static int *val2 = NULL;
static int *val3 = NULL;
static int *val4 = NULL;
static int *val5 = NULL;
static int *val6 = NULL;
static int *val7 = NULL;

int qsort_compare(void* a, void* b) {
  if (*((int*)a) <= *((int*)b)) {
    return 1;
  } else {
    return 0;
  }
}

char* test_qsort() {
  array = DArray_create(sizeof(int), 100);

  val1 = DArray_new(array);
  val2 = DArray_new(array);
  val3 = DArray_new(array);
  val4 = DArray_new(array);
  val5 = DArray_new(array);
  val6 = DArray_new(array);
  val7 = DArray_new(array);

  DArray_set(array, 0, val1);
  DArray_set(array, 1, val2);
  DArray_set(array, 2, val3);
  DArray_set(array, 3, val4);
  DArray_set(array, 4, val5);
  DArray_set(array, 5, val6);
  DArray_set(array, 6, val7);

  *val1 = 4;
  *val2 = 2;
  *val3 = 7;
  *val4 = 10;
  *val5 = 8;
  *val6 = 1;
  *val7 = 3;

  DArray_qsort(array, qsort_compare);

  int i;

  for (i = 0; i < DArray_count(array)+1; i++) {
    printf("%d\n", *((int*)array->contents[i]));
  }

  return NULL;
}

char* all_tests() {
  mu_suite_start();

  mu_run_test(test_qsort);

  return NULL;
}

RUN_TESTS(all_tests);
