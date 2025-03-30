typedef struct char_frequency_tuple {
    char character;
    int frequency;
} CharFrequencyTuple;

typedef struct sorted_node {
    CharFrequencyTuple tuple;
    struct sorted_node *next;
} SortedNode;

SortedNode *create_sorted_node(char character, int frequency);
