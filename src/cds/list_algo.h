#ifndef CDS_LIST_ALGO_H_
#define CDS_LIST_ALGO_H_

#include <stdlib.h>

#include "list.h"

void List_bubble_sort(List* list, int (*compare) (void*, void*));

#endif

