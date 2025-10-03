#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

typedef struct Node {
    struct Node *next;
    int value;
} Node;

#define NODES_VALUE_BOUND 50

int main() {
    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    head->value = __VERIFIER_nondet_int() % NODES_VALUE_BOUND;

    Node *current = head;

    // Construct a linked list with non-deterministic length
    while (__VERIFIER_nondet_int() % 2 == 0) {
        Node *new_node = malloc(sizeof(Node));
        new_node->value = __VERIFIER_nondet_int() % NODES_VALUE_BOUND;
        new_node->next = NULL;
        current->next = new_node;
        current = new_node;
    }

    // Calculate the sum of all node values and the count of nodes
    int node_count = 0;
    int total_sum = 0;
    current = head;
    while (current != NULL) {
        total_sum += current->value;
        node_count++;
        current = current->next;
    }

    // Properties to verify
    __VERIFIER_assert(node_count > 0);

    // Clean up
    current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}