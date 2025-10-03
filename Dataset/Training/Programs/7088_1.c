#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *create_node(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void append(Node **list, int value) {
    Node *new_node = create_node(value);
    if (*list == NULL) {
        *list = new_node;
    } else {
        Node *temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

int sum_of_squares(Node *list) {
    int sum = 0;
    while (list != NULL) {
        sum += list->value * list->value;
        list = list->next;
    }
    return sum;
}

int main() {
    Node *list = NULL;
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    for (int i = 0; i < n; ++i) {
        int value = __VERIFIER_nondet_int();
        assume_abort_if_not(value >= -100 && value <= 100);
        append(&list, value);
    }

    int sum = sum_of_squares(list);

    // Verify the meaningful condition: sum should be non-negative
    __VERIFIER_assert(sum >= 0);

    // Clean up the list
    Node *current = list;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}