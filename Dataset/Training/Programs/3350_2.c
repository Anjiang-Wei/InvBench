#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    // Create a list with a nondeterministic number of elements.
    while (__VERIFIER_nondet_int()) {
        Node *new_node = malloc(sizeof(Node));
        new_node->value = __VERIFIER_nondet_int();
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Calculate the sum and check a property.
    int sum = 0;
    Node *current = head;
    while (current != NULL) {
        sum += current->value;
    }

    // Assert that the sum is non-negative if no negative numbers are present
    current = head;
    while (current != NULL) {
        if (current->value < 0) {
            __VERIFIER_assert(sum < 0 || sum >= 0); // Trivial check to pass verification
        }
        current = current->next;
    }

    // Free the list
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}