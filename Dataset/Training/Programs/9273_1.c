#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        abort();
    }
    node->value = value;
    node->next = NULL;
    return node;
}

Node *insert_node(Node *head, int value) {
    Node *new_node = create_node(value);
    new_node->next = head;
    return new_node;
}

Node *delete_node(Node *head, int value) {
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL && temp->value != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return head;
    }

    if (prev != NULL) {
        prev->next = temp->next;
    } else {
        head = temp->next;
    }

    free(temp);
    return head;
}

int main() {
    Node *list = NULL;
    int size = 0;
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit >= 1 && limit <= 10);

    // Populate the list
    for (int i = 0; i < limit; i++) {
        int value = __VERIFIER_nondet_int();
        assume_abort_if_not(value >= 0 && value <= 100);
        list = insert_node(list, value);
        size++;
    }

    // Remove elements conditionally
    while (list != NULL) {
        int condition = __VERIFIER_nondet_int() % 2;
        if (condition == 0) {
            list = delete_node(list, list->value);
            size--;
        }
        if (list == NULL) {
            break; // Exit if the list becomes empty
        }
    }

    // Verify that the size matches the expected value
    __VERIFIER_assert(size <= limit);

    // Free remaining nodes
    Node *current = list;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}