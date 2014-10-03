#include "minunit.h"
#include <cds/list.h>
#include <cds/list_algo.h>
#include <assert.h>
#include <stdio.h>

static List *list = NULL;
static List *src = NULL;
static List *dest = NULL;


int test1 = 2;
int test2 = 4;
int test3 = 77;
int test4 = 3;
int test5 = 9;
int test6 = 11;
int test7 = 22;

int compare(void* n1, void* n2) {
  int* in1 = n1;
  int* in2 = n2;
  if ((*in1) < (*in2)) 
    return 0;
  return 1;
}

char *test_bubble() {
  list = List_create();
  List_push(list, test1);
  List_push(list, test2);
  List_push(list, test3);
  List_push(list, test4);
  List_push(list, test5);
  List_push(list, test6);
  List_push(list, test7);
  List_bubble_sort(list, compare);
  int c;
  LIST_FOREACH(list, first, next, cur) {
    printf("%d\n", cur->value);
  }
  
  mu_assert(list != NULL, "Failed to create list.");
  return NULL;
}

char *all_tests() {

  mu_suite_start();
  mu_run_test(test_bubble);

  return NULL;
}

RUN_TESTS(all_tests);

