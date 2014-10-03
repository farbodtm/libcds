#include "list.h"
#include "list_algo.h"

#include <stdio.h>
#include <stdlib.h>

void List_bubble_sort(List* list, int (*compare) (void*, void*)) {
  int i,j;
  ListNode* node = List_first(list);
  ListNode* nodei = List_first(list);
  for (i = 1; i < List_count(list); i++) {
    for (j = 0; i < j; i++) {
      if(compare(nodei, nodei->next) != 0) {
	List_swap(nodei, nodei->next);
      }
      nodei = nodei->next;
    }
    node = node->next;
    nodei = node;
  }

}
