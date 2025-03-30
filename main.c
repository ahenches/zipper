#include <stdio.h>
#include <stdlib.h>

#include "./main.h"
#include "./file_reader_util.h"
#include "./huffman_code.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char *argv[]) {
    HashMap *m = fill_map(read_file("symb.txt"));

    for (int i = 0; i < 256; i++) {
        if (m->value[i] == 0) {
            continue;
        }
        printf("char: (%c / %d) number:  %d \n", i, i, m->value[i]);
    }

    // SortedNode *sorted_node = create_sorted_node();
    //
    // for (int i = 0; i < sorted_node->size; i++) {
    //     printf("char: (%c / %d) number:  %d \n", sorted_node->tuple[i].character, sorted_node->tuple[i].character, sorted_node->tuple[i].frequency);
    // }

    free(m->value);
    free(m);
    // free(sorted_node->tuple);
    // free(sorted_node);

    return EXIT_SUCCESS;
}


