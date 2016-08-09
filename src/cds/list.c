#include <cds/list.h>
#include <cds/dbg.h>

List* List_create() {
  return calloc(1, sizeof(List));
}

void List_destroy(List* list) {
  LIST_FOREACH(list, first, next, cur) {
    if(cur->prev) {
      free(cur->prev);
    }
  }

  free(list->last);
  free(list);
}

void List_clear(List* list) {
  LIST_FOREACH(list, first, next, cur) {
    free(cur->value);
  }
}

void List_clear_destroy(List* list) {
  LIST_FOREACH(list, first, next, cur) {
    free(cur->value);
    if(cur->prev) {
      free(cur->prev);
    }
  }

  free(list->last);
  free(list);
}

void List_push(List* list, void* value) {
  ListNode* node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if (list->last == NULL) {
    list->first = node;
    list->last = node;
  } else {
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
  }

  list->count++;

error:
  return;
}

void* List_pop(List* list) {
  ListNode *node = list->last;
  return node != NULL ? List_remove(list, node) :NULL;
}

void List_remove_duplicates(List* list) {
  ListNode* current = list->first;
  // Need a hashmap

}

void List_unshift(List* list, void* value) {
  ListNode* node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if(list->first == NULL) {
    list->first = node;
    list->last = node;
  } else {
    node->next = list->first;
    list->first->prev = node;
    list->first = node;
  }

  list->count++;

error:
  return;
}

void* List_shift(List* list) {
  ListNode* node = list->first;
  return node != NULL ? List_remove(list, node) : NULL;
}

void* List_remove(List* list, ListNode* node) {
  void* result = NULL;

  check(list->first && list->last, "List is empty.");
  check(node, "node can't be NULL");

  if(node == list->first && node == list->last) {
    list->first = NULL;
    list->last = NULL;
  } else if(node == list->first) {
    list->first = node->next;
    check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
    list->first->prev = NULL;
  } else if(node == list->last) {
    list->last = node->prev;
    check(list->last != NULL, "Invalid list, somehow got a last that is NULL.");
    list->last->next = NULL;
  } else {
    ListNode *after = node->next;
    ListNode *before = node->prev;
    after->prev = before;
    before->next = after;
  }

  list->count--;
  result = node->value;

  free(node);

error:
  return result;
}

void List_copy(List* dest, List* src) {
  LIST_FOREACH(src, first, next, cur) {
    List_push(dest, cur->value);
  }
}

List* List_join(List* list1, List* list2) {
  List* new_list = List_create();

  List_copy(new_list, list1);
  List_copy(new_list, list2);

  return new_list;
}

void List_swap(ListNode* n1, ListNode* n2) {
  void* tmp;
  tmp = n2->value;
  n2->value = n1->value;
  n1->value = tmp;
}
 
List** List_split(List* list, int number, ...) {
  va_list lists;
  va_start(lists, number);

  List** re = calloc(number+1, sizeof(List*));

  int i;
  ListNode* point = NULL;
  ListNode* last_point = list->first;
  for (i = 0; i < number+1; i++) {
    if (i != number) {
      point = va_arg(lists, ListNode*);
    } else {
      point = list->last;
    }
    List* new = List_create();
    ListNode* cur = NULL;
    for (cur = last_point; cur != point->next; cur = cur->next) {
      List_push(new, cur->value);
    }
    re[i] = new;
    last_point = point->next;
  }
  return re;
}

ListNode* List_find(List* list, void* value) {
  LIST_FOREACH(list, first, next, cur) {
    if (cur->value == value) {
      return cur;
    }
  }
  return NULL;
}


