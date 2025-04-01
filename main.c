#include <stdio.h>
#include <stdlib.h>

#include "./file_reader_util.h"
#include "./linked_list.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char *argv[]) {
    HashMap *m = fill_map(read_file("symb.txt"));

    SortedNode *sorted_node = convert_to_linked_list(m);

    printf("\n\n");


    HuffmanTree *tree = create_huffman_tree(sorted_node);
    print_huffman_tree(tree);


    free(m->value);
    free(m);

    free_linked_list(sorted_node);
    free_huffman_tree(tree);

    return EXIT_SUCCESS;
}


