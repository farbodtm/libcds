#include "minunit.h"
#include <cds/list.h>
#include <assert.h>
#include <stdio.h>

static List *list = NULL;
static List *src = NULL;
static List *dest = NULL;


char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";
char *test4 = "test4 data";
char *test5 = "test5 data";
char *test6 = "test6 data";

char *test_create() {
  list = List_create();
  mu_assert(list != NULL, "Failed to create list.");

  return NULL;
}

char *test_destroy() {
  List_clear_destroy(list);

  return NULL;
}

char *test_push_pop() {
  List_push(list, test1);
  mu_assert(List_last(list) == test1, "Wrong last value.");

  List_push(list, test2);
  mu_assert(List_last(list) == test2, "Wrong last value.");

  List_push(list, test3);
  mu_assert(List_last(list) == test3, "Wrong last value.");
  mu_assert(List_count(list) == 3, "Wrong count on push.");

  char *val = List_pop(list);
  mu_assert(val == test3, "Wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == test2, "Wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == test1, "Wrong value on pop.");

  mu_assert(List_count(list) == 0, "Wrong count after pop.");

  return NULL;

}

char *test_unshift() {
  List_unshift(list, test1);
  mu_assert(List_first(list) == test1, "Wrong first value.");

  List_unshift(list, test2);
  mu_assert(List_first(list) == test2, "Wrong first value.");

  List_unshift(list, test3);
  mu_assert(List_first(list) == test3, "Wrong first value.");

  mu_assert(List_count(list) == 3, "Wrong count on unshift.");

  return NULL;
}

char *test_remove() {
  char *val = List_remove(list, list->first->next);

  mu_assert(val == test2, "Wrong removed element.");
  mu_assert(List_count(list) == 2, "Wrong count after remove.");
  mu_assert(List_first(list) == test3, "Wrong first after remove.");
  mu_assert(List_last(list) == test1, "Wrong last after remove.");

  return NULL;
}

char *test_shift() {
  mu_assert(List_count(list) != 0, "Wrong count before shift.");

  char *val = List_shift(list);
  mu_assert(val == test3, "Wrong value on shift.");

  val = List_shift(list);
  mu_assert(val == test1, "Wrong value on shift.");
  mu_assert(List_count(list) == 0, "Wrong count after shift.");

  return NULL;
}

char* test_copy() {
  src = List_create();
  dest = List_create();
  List_push(src, test1);
  List_push(src, test2);
  List_push(src, test3);

  List_copy(dest, src);

  mu_assert(List_count(dest) == 3, "Wrong copy - count.");
  mu_assert(List_first(dest) == test1, "Wrong copy - first.");
  mu_assert(List_last(dest) == test3, "Wrong copy - last.");

  return NULL;
}

char* test_split() {
  List* list_test = List_create();
  List_push(list_test, test1);
  List_push(list_test, test2);
  List_push(list_test, test3);
  List_push(list_test, test4);
  List_push(list_test, test5);
  List_push(list_test, test6);

  ListNode* split1 = List_find(list_test, test3);
  ListNode* split2 = List_find(list_test, test5);

  mu_assert(split1->value == test3, "Ridi");
  mu_assert(split2->value == test5, "Ridi");

  List** splits = List_split(list_test, 2, split1, split2);
  mu_assert(splits[0]->first->value == list_test->first->value, "Ridi");
  mu_assert(splits[0]->first->next->value == list_test->first->next->value, "Ridi");
  mu_assert(splits[0]->last->value == list_test->first->next->next->value, "Ridi");

  mu_assert(splits[1]->first->value == list_test->first->next->next->next->value, "Ridi");
  mu_assert(splits[1]->last->value == list_test->first->next->next->next->next->value, "Ridi");

  mu_assert(splits[2]->first->value == list_test->last->value, "Ridi");

  return NULL;
}

char *all_tests() {
  mu_suite_start();

  mu_run_test(test_create);
  mu_run_test(test_copy);
  mu_run_test(test_split);
  mu_run_test(test_push_pop);
  mu_run_test(test_unshift);
  mu_run_test(test_remove);
  mu_run_test(test_shift);
  mu_run_test(test_destroy);

  return NULL;
}

RUN_TESTS(all_tests);

