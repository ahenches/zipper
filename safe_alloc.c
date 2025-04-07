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

void *safe_calloc(size_t num, size_t size) {
    void *ptr = calloc(num, size);
    if (ptr == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
