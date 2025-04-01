#include <stdio.h>
#include <stdlib.h>

#include "./safe_alloc.h"
void *safe_alloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
