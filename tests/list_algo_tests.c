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
  if ((*in1) > (*in2)) 
    return 0;
  return 1;
}

char *test_bubble() {
  list = List_create();
  int* t1 = &test1;
  int* t2 = &test2;
  int* t3 = &test3;
  int* t4 = &test4;
  int* t5 = &test5;
  int* t6 = &test6;
  int* t7 = &test7;
  List_push(list, t1);
  List_push(list, t2);
  List_push(list, t3);
  List_push(list, t4);
  List_push(list, t5);
  List_push(list, t6);
  List_push(list, t7);

  ListNode* node = list->first->next->next;


  //printf("%d\n", (*(int*)node->value));
  //printf("%d\n", compare(node->value, node->next->value));


  List_bubble_sort(list, compare);

  //int c;
  /*LIST_FOREACH(list, first, next, cur) {
    printf("%d\n", (*(int*)(cur->value)));
  }*/
  
  mu_assert(list != NULL, "Failed to create list.");
  return NULL;
}

char *test_merge() {
  list = List_create();
  int* t1 = &test1;
  int* t2 = &test2;
  int* t3 = &test3;
  int* t4 = &test4;
  int* t5 = &test5;
  int* t6 = &test6;
  int* t7 = &test7;
  List_push(list, t1);
  List_push(list, t2);
  List_push(list, t3);
  List_push(list, t4);
  List_push(list, t5);
  List_push(list, t6);
  List_push(list, t7);

  //ListNode* node = list->first->next->next;


  //printf("%d\n", (*(int*)node->value));
  //printf("%d\n", compare(node->value, node->next->value));


  List* sorted_list = List_merge_sort(list, compare);

  /*int c;
  LIST_FOREACH(sorted_list, first, next, cur) {
    printf("%d\n", (*(int*)(cur->value)));
  }*/
  
  mu_assert(list != NULL, "Failed to create list.");
  return NULL;
}

char *all_tests() {

  mu_suite_start();
  mu_run_test(test_bubble);
  mu_run_test(test_merge);

  return NULL;
}

RUN_TESTS(all_tests);

