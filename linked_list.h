#include "huffman_code.h"

typedef struct sorted_node {
    HuffmanNode *value;
    struct sorted_node *next;
} SortedNode;


SortedNode *create_sorted_node(char character, int frequency);
SortedNode *insert_sorted_node(SortedNode **head, char character, int frequency);
void print_linked_list(SortedNode *head);
void free_linked_list(SortedNode *head);

SortedNode *convert_to_linked_list(HashMap *map);

HuffmanNode *create_huffman_node(char character, int frequency);
HuffmanTree *create_huffman_tree(SortedNode *sorted_node);
HuffmanNode *create_huffman_tree_rec(SortedNode *sorted_list);
