#include "dynarr.h"
#include <stdio.h>
#include <stdlib.h>

DynArr* create_dynarr() {
  DynArr *arr;
  int length;

  arr = malloc(sizeof(DynArr));
  if (!arr) {
    printf("Memory allocation failed\n");
    return NULL;
  }

  arr->data = malloc(sizeof(int) * 4);
  if (!arr->data) {
    printf("Memory allocation failed\n");
    free(arr);
    return NULL;
  }

  arr->capacity = 4;
  arr->length = 0;

  return arr;
}

DynArr* resize_dyn_arr(DynArr *arr) {
  if (!arr) {
    printf("Dynamic array not found\n");
    return NULL;
  }

  size_t new_capacity = arr->capacity * 2;
  int *new_data = realloc(arr->data, sizeof(int) * new_capacity);

  if (!new_data) {
    printf("Memory reallocation failed\n");
    return NULL;
  }

  arr->data = new_data;
  arr->capacity = new_capacity;

  return arr;
}

void push_element(DynArr *arr, int element) {
  if (!arr) {
    printf("Dynamic array not found\n");
    return;
  }
  
  if (arr->length >= arr->capacity) {
    if (resize_dyn_arr(arr) == NULL) {
      printf("Failed to resize, cannot push element\n");
      return;
    }
  }

  arr->data[arr->length] = element;
  arr->length += 1;
}

void delete_element(DynArr *arr, size_t idx) {
  if (!arr) {
    printf("Dynamic array not found\n");
    return;
  }

  if (idx >= arr->length) {
    printf("Out of bounds\n");
    return;
  }

  for (size_t i = idx; i < arr->length - 1; i++) {
    arr->data[i] = arr->data[i + 1];
  }

  arr->length -= 1;
}

size_t length(DynArr *arr) {
  return arr ? arr->length : 0;
}
