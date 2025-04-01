#include <stdio.h>
#include <stdlib.h>

#include "./linked_list.h"
#include "./safe_alloc.h"

SortedNode *convert_to_linked_list(HashMap *map) {
    SortedNode *head = NULL;

    for (int i = 0; i < 256; i++) {
        if (map->value[i] > 0) {
           insert_sorted_node(&head, i, map->value[i]);
        }
    }
    return head;
}


SortedNode *create_sorted_node(char character, int frequency) {
    SortedNode *node = (SortedNode *) safe_alloc(sizeof(SortedNode));
    node->value = (HuffmanNode *) safe_alloc(sizeof(HuffmanNode));

    node->value->character = character;
    node->value->frequency = frequency;
    node->next = NULL;
    return node;
}


SortedNode *insert_sorted_node(SortedNode **head, char character, int frequency) {
    SortedNode *new_node = create_sorted_node(character, frequency);
    if (*head == NULL) {
        *head = new_node;
        return new_node;
    }
    if ((*head)->value->frequency > new_node->value->frequency) {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    SortedNode *current = *head;

    while (current->next != NULL && current->next->value->frequency < new_node->value->frequency) {
        current = current->next;
    }
    if (current->next == NULL) {
        current->next = new_node;
    }
    else { // (current->next->tuple.frequency >= new_node->tuple.frequency) {
        new_node->next = current->next;
        current->next = new_node;
    }
    return new_node;
}

void print_linked_list(SortedNode *head) {
    SortedNode *current = head;
    while (current != NULL) {
        printf("char: (%c / %d) number:  %d \n", current->value->character, current->value->character, current->value->frequency);
        current = current->next;
    }
}

void free_linked_list(SortedNode *head) {
    SortedNode *current = head;
    SortedNode *next_node;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

HuffmanTree *create_huffman_tree(SortedNode *head) {

    HuffmanTree *tree = (HuffmanTree *) safe_alloc(sizeof(HuffmanTree));

    tree->root = create_huffman_tree_rec(head);
    return tree;
}

HuffmanNode *create_huffman_tree_rec(SortedNode *head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        printf("WEIRD SHIT\n");
        return head->value;
    }

    int new_frequency = head->value->frequency + head->next->value->frequency;

    SortedNode *new_head = head->next->next;
    SortedNode *last_inserted = insert_sorted_node(&new_head, '\0', new_frequency);
    HuffmanNode *left_node = head->value;
    HuffmanNode *right_node = head->next->value;
    last_inserted->value->left = left_node;
    last_inserted->value->right = right_node;

    printf("left: %c (%d) right: %c (%d) new: %d\n", left_node->character, left_node->frequency, right_node->character, right_node->frequency, new_frequency);
    return create_huffman_tree_rec(new_head);
}

