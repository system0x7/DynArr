# DynArr - A Dynamic Integer Array Library in C
A basic implementation of dynamic integer arrays / lists in C with automatic resizing.

## Building the Library
```bash
# Linux
gcc -c -fPIC src/dynarr.c -o dynarr.o
gcc -shared dynarr.o -o libdynarr.so

# MacOS
gcc -c -fPIC src/dynarr.c -o dynarr.o
gcc -dynamiclib dynarr.o -o libdynarr.dylib
```

## Usage

Include the header in the program:
```c
#include "dynarr.h"
```


## Example
```c
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "dynarr.h"


int main() {
  DynArr *arr = create_dynarr();
  push_element(arr, 5);
  push_element(arr, 6);
  push_element(arr, 7);
  push_element(arr, 8);
  push_element(arr, 9);

  for (size_t i = 0; i < length(arr); i++) {
    printf("Element at index %zu: %d\n", i, arr->data[i]);
  }

  // Delete element by index 
  delete_element(arr, 1);

  free(arr->data);
  free(arr);

  return 0;
}
```

Compile the program with the library:
```bash
# -I./src = let GCC find dynarr.h
# -L. = look for libraries in the current directory 
# -ldynarr = link against libdynarr.so
gcc program.c -I./src -L. -ldynarr -o program
```

To run it: 
```bash
LD_LIBRARY_PATH=. ./program      # Linux
DYLD_LIBRARY_PATH=. ./program    # macOS
```
