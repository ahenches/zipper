#include <stdio.h>
#include <stdlib.h>

#include "./huffman_code.h"
#include "./safe_alloc.h"

HashMap *fill_map(FILE *file) {
    HashMap *map = (HashMap *) safe_alloc(sizeof(HashMap));

    map->value = (int *) safe_alloc(sizeof(int) * 256);

    int char_read;
    while ((char_read = fgetc(file)) != EOF) {
        printf("char: (%c)", char_read);
        map->value[char_read]++;
    }

    return map;
}


HuffmanNode *create_huffman_node(char character, int frequency) {
    HuffmanNode *node = (HuffmanNode *) safe_alloc(sizeof(HuffmanNode));

    node->character = character;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void print_huffman_tree(HuffmanTree *tree) {
    if (tree == NULL) {
        return;
    }
    print_huffman_tree_rec(tree->root, 0);
}

void print_huffman_tree_rec(HuffmanNode *node, int depth) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("Node: %c (%d)\n", node->character, node->frequency);
    print_huffman_tree_rec(node->left, depth + 1);
    print_huffman_tree_rec(node->right, depth + 1);
}

void free_huffman_tree(HuffmanTree *tree) {
    if (tree == NULL) {
        return;
    }
    free_huffman_tree_rec(tree->root);
    free(tree);
}

void free_huffman_tree_rec(HuffmanNode *node) {
    if (node == NULL) {
        return;
    }
    free_huffman_tree_rec(node->left);
    free_huffman_tree_rec(node->right);
    free(node);
}
