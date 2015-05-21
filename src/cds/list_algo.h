#ifndef CDS_LIST_ALGO_H_
#define CDS_LIST_ALGO_H_

#include <stdlib.h>

#include "list.h"

typedef int (*List_compare) (void*, void*);

void List_bubble_sort(List* list, int (*compare) (void*, void*));

List* List_merge_sort(List* list, int (*compare) (void*, void*));

#endif

