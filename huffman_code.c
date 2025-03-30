#include <stdio.h>
#include <stdlib.h>

#include "./huffman_code.h"

HashMap *fill_map(FILE *file) {
    HashMap *map = (HashMap *) malloc(sizeof(HashMap));
    if (map == NULL) {
        perror("Error allocating memory for map");
        return NULL;
    }
    map->value = (int *) malloc(sizeof(int) * 256);

    int char_read;
    while ((char_read = fgetc(file)) != EOF) {
        printf("char: (%c)", char_read);
        map->value[char_read]++;
    }

    return map;
}

// SortedNode *create_sorted_list(HashMap *map) {
//     SortedNode *sorted_list = (SortedNode *) malloc(sizeof(SortedNode));
//     if (sorted_list == NULL) {
//         perror("Error allocating memory for sorted list");
//         return NULL;
//     }
//
//     sorted_list->size = 0;
//     for (int i = 0; i < 256; i++) {
//         if (map->value[i] > 0) {
//             sorted_list->size++;
//         }
//     }
//
//     sorted_list->tuples = (CharFrequencyTuple *) malloc(sizeof(CharFrequencyTuple) * sorted_list->size);
//     if (sorted_list->tuples == NULL) {
//         perror("Error allocating memory for tuples");
//         free(sorted_list);
//         return NULL;
//     }
//
//
//   int index = 0;
//     for (int i = 0; i < 256; i++) {
//         if (map->value[i] > 0) {
//             sorted_list->tuples[index].character = i;
//             sorted_list->tuples[index].frequency = map->value[i];
//             index++;
//         }
//     }
//
//     return sorted_list;
// }
//



/* SortedNode *create_sorted_list(HashMap *map) {
    SortedNode *sorted_list = (SortedNode *) malloc(sizeof(SortedNode));
    if (!sorted_list) {
        perror("Error allocating memory for sorted list");
        return NULL;
    }

    // Allocate the maximum possible size (worst case)
    sorted_list->tuples = (CharFrequencyTuple *) malloc(256 * sizeof(CharFrequencyTuple));
    if (!sorted_list->tuples) {
        perror("Error allocating memory for tuples");
        free(sorted_list);
        return NULL;
    }

    // Single loop: Count valid entries & populate the array
    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (map->value[i] > 0) {
            sorted_list->tuples[index].character = i;
            sorted_list->tuples[index].frequency = map->value[i];
            index++;
        }
    }

    // Reduce the allocated memory to the actual size needed
    sorted_list->size = index;
    sorted_list->tuples = (CharFrequencyTuple *) realloc(sorted_list->tuples, sorted_list->size * sizeof(CharFrequencyTuple));

    if (!sorted_list->tuples && sorted_list->size > 0) { // realloc failure (only if size > 0)
        perror("Error resizing memory for tuples");
        free(sorted_list);
        return NULL;
    }

    return sorted_list;
}
*/
