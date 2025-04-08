#include <stdio.h>
#include <stdlib.h>

#include "./file_reader_util.h"
#include "./linked_list.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

int main(int argc, char *argv[]) {
    char *file_content = file_to_string(read_file("symb.txt"));
    printf("%s\n", file_content);

    HashMap *m = fill_map(file_content);
    SortedNode *sorted_node = convert_to_linked_list(m);

    HuffmanTree *tree = create_huffman_tree(sorted_node);


    print_huffman_tree(tree);
    convert_symbols(tree);

    free(m->value);
    free(m);

    free_huffman_tree(tree);
    free(file_content);

    return EXIT_SUCCESS;
}


