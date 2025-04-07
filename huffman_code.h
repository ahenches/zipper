typedef struct hash_map {
  int *value;
} HashMap;

HashMap *fill_map(char *file_content);

typedef struct huffman_node {
    char character;
    int frequency;
    struct huffman_node *left;
    struct huffman_node *right;
} HuffmanNode;

typedef struct huffman_tree {
    HuffmanNode *root;
} HuffmanTree;


void print_huffman_tree(HuffmanTree *tree);
void print_huffman_tree_rec(HuffmanNode *node, int depth);
void free_huffman_tree(HuffmanTree *tree);
void free_huffman_tree_rec(HuffmanNode *node);


char **convert_symbols(HuffmanTree *tree);
