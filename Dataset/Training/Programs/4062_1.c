#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Nondeterministic function
extern int __VERIFIER_nondet_int(void);

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Function to create a new linked list node
Node *create_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

int main() {
    Node *head = create_node(0); // Initial list node
    Node *current = head;

    // Create a linked list with nondeterministic values and length
    int length = 0;
    while (__VERIFIER_nondet_int()) {
        int value = __VERIFIER_nondet_int();
        current->next = create_node(value);
        current = current->next;
        length++;

        if (length >= 50) {
            break; // Limit the list length to prevent infinite loop
        }
    }

    // Traverse the linked list and find the maximum value
    int max_value = head->value;
    current = head;
    while (current != NULL) {
        if (current->value > max_value) {
            max_value = current->value;
        }
        current = current->next;
    }

    // Verify the post condition
    __VERIFIER_assert(max_value >= head->value);

    // Free the linked list
    current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}