#include "list.h"
#include "list_algo.h"
#include "dbg.h"

#include <stdio.h>
#include <stdlib.h>

void List_bubble_sort(List* list, int (*compare) (void*, void*)) {
  int i,j;
  int swap = 0;
  if (List_count(list) < 2) {
    return;
  }
  ListNode* nodei = list->first;
  for (i = List_count(list)-1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      if(compare(nodei->value, nodei->next->value) != 0) {
	List_swap(nodei, nodei->next);
	swap = 1;
      }
      nodei = nodei->next;
    }
    if (!swap) {
      break;
    }
    swap = 0;
    nodei = list->first;
  }
}

List* List_merge(List* left, List* right, List_compare compare) {
  int count;
  List* merged_list = List_create();

  for (count = List_count(left) + List_count(right); count > 0; count--) {
    // if left is empty just push elements from right
    if (List_count(left) == 0) {
      List_push(merged_list, right->first->value);
      List_shift(right);
    } else if (List_count(right) == 0){ // if right is empty push elements from left
      List_push(merged_list, left->first->value);
      List_shift(left);
      // if compare is true left value goes frist
    } else if (compare(left->first->value, right->first->value)) {
      List_push(merged_list, left->first->value);
      List_shift(left);
    } else {
      List_push(merged_list, right->first->value);
      List_shift(right);
    }
  }

  return merged_list;
}

List* List_merge_sort(List* list, List_compare compare) {
  // base case, if there is only one node return it
  if (List_count(list) == 1) {
    return list;
  } 

  List* left = List_create();
  List* right = List_create();

  int middle = List_count(list)/2;


  // populate left and right lists
  LIST_FOREACH(list, first, next, cur) {
    if (middle > 0) {
      List_push(left, cur->value);
    } else {
      List_push(right, cur->value);
    }
    middle--;
  }

  List* sorted_left = List_merge_sort(left, compare);
  List* sorted_right = List_merge_sort(right, compare);

  // cleaning up the memory
  if (sorted_left != left)  List_destroy(left);
  if (sorted_right != right)  List_destroy(right);

  return List_merge(sorted_left, sorted_right, compare);
}
