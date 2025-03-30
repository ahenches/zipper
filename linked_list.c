#include <stdio.h>
#include <stdlib.h>

#include "./linked_list.h"

SortedNode *create_sorted_node(char character, int frequency) {
    SortedNode *node = (SortedNode *) malloc(sizeof(SortedNode));
    if (node == NULL) {
        perror("Error allocating memory for sorted node");
        return NULL;
    }
    node->tuple.character = character;
    node->tuple.frequency = frequency;
    node->next = NULL;
    return node;
}

void insert_sorted_node(SortedNode **head, char character, int frequency) {
    SortedNode *new_node = create_sorted_node(character, frequency);
    if (new_node == NULL) {
        return;
    }

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    if ((*head)->tuple.frequency > new_node->tuple.frequency) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    SortedNode *current = *head;

    while (current->next != NULL && current->next->tuple.frequency < new_node->tuple.frequency) {
        current = current->next;
    }
    if (current->next->tuple.frequency >= new_node->tuple.frequency) {
        new_node->next = current->next;
        current->next = new_node;
    } else { // current->next == NULL
        current->next = new_node;
        return;
    }

}

