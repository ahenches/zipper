#include <stdio.h>
#include <stdlib.h>

#include "./huffman_code.h"
#include "./safe_alloc.h"

HashMap *fill_map(char *file_content) {
    HashMap *map = (HashMap *) safe_alloc(sizeof(HashMap));

    map->value = (int *) safe_calloc(256, sizeof(int));

    while (*file_content != '\0') {
        map->value[(unsigned char)*file_content]++;
        file_content++;
    }

    return map;
}

void convert_symbols(HuffmanTree *tree) {

    if (tree == NULL) {
        return;
    }
    char code[256];
    code[0] = '\0'; // Initialize the code string

    convert_symbols_rec(tree->root, code, 0);
}

void convert_symbols_rec(HuffmanNode *node, char *code, int depth) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        printf("Symbol: %c, Code: %s\n", node->character, code);
        return;
    }
    code[depth+1] = '\0';
    code[depth] = '0';
    convert_symbols_rec(node->left, code, depth + 1);
    code[depth+1] = '\0';
    code[depth] = '1';
    convert_symbols_rec(node->right, code, depth + 1);
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
    if (node->left == NULL && node->right == NULL) {
        printf("Leaf: %c (%d)\n", node->character, node->frequency);
    } else {
        printf("Internal: (%d)\n", node->frequency);
    }

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
