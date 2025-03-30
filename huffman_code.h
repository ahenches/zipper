#include "./linked_list.h"

typedef struct hash_map {
  int *value;
} HashMap;

HashMap *fill_map(FILE *file);

typedef struct huffman_node {
    char character;
    int frequency;
    struct huffman_node *left;
    struct huffman_node *right;
} HuffmanNode;

typedef struct huffman_tree {
    HuffmanNode *root;
} HuffmanTree;

HuffmanTree *create_huffman_tree(SortedNode *sorted_node);
