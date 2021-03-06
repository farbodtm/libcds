#ifndef CDS_LIST_H
#define CDS_LIST_H

#include <stdlib.h>
#include <stdarg.h>

struct ListNode;

// Node 
typedef struct ListNode {
  struct ListNode* next;
  struct ListNode* prev;
  void* value;
} ListNode;

// List 
typedef struct List {
  int count;
  ListNode* first;
  ListNode* last;
} List;

// Initialize
List* List_create();
void List_destroy(List* list);
void List_clear(List* list);
void List_clear_destroy(List* list);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

// Operations
void List_push(List* list, void* value);
void* List_pop(List* list);

void List_unshift(List* list, void* value);
void* List_shift(List* list);

void* List_remove(List* list, ListNode* node);

// Extra Functions
void List_copy(List* dest, List* src);
void List_remove_duplicates(List* list);
void List_swap(ListNode* n1, ListNode* n2);

List* List_join(List* list1, List* list2);
List** List_split(List* list, int number, ...); 

ListNode* List_find(List* list, void* value);

// Foreach macro
#define LIST_FOREACH(L, S, M, V) ListNode* _node = NULL;\
  ListNode* V = NULL;\
  for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif

