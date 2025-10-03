#include <assert.h>
#include <stdlib.h>
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

typedef struct Node {
    int value;
    struct Node *next;
} Node;

int main() {
    // Initialize the head of a linked list
    Node *head = malloc(sizeof(Node));
    head->value = 0;
    head->next = NULL;

    Node *current = head;
    int sum = 0;
    int max_value = 100; // constraint for the maximum value in the list

    // Populate the list with values until a nondeterministic condition
    while (__VERIFIER_nondet_int()) {
        current->next = malloc(sizeof(Node));
        current = current->next;
        current->value = __VERIFIER_nondet_int() % max_value; // values between 0 and max_value
        current->next = NULL;
    }

    // Calculate sum of the list and check for a condition
    current = head;
    while (current != NULL) {
        sum += current->value;
    }

    // Check if sum is within a certain range
    __VERIFIER_assert(sum < max_value * 10);

    // Free the list
    current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}