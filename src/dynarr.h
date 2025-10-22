#ifndef DYNARR_H
#define DYNARR_H

#include <stddef.h>

typedef struct {
  int *data;
  size_t capacity;
  size_t length;
} DynArr;

DynArr* create_dynarr(void);
DynArr* resize_dyn_arr(DynArr *arr);
void push_element(DynArr *arr, int element);
void delete_element(DynArr *arr, size_t idx);
size_t length(DynArr *arr);

#endif
