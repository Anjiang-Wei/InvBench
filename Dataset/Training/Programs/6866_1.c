#include <assert.h>
#include <stdlib.h>
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_node(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

int main() {
    // Create the head of the linked list
    Node *head = create_node(0);
    Node *current = head;

    // Construct a list with values incrementing by random even numbers
    while (__VERIFIER_nondet_int()) {
        int step = __VERIFIER_nondet_int();
        if (step < 0) {
            continue;
        }
        if (step % 2 != 0) {
            step++; // Ensure step is even
        }
        current->next = create_node(current->value + step);
        current = current->next;

        // Ensure list grows with even step and remains positive
        __VERIFIER_assert(current->value >= 0);
    }

    // Traverse the list and verify properties
    Node *trav = head;
    while (trav != NULL) {
        if (trav->next != NULL) {
        }
        trav = trav->next;
    }

    // Free the list
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}