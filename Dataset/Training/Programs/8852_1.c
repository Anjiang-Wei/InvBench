#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Function to calculate the sum of values in a linked list
int calculate_sum(Node *head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->value;
        head = head->next;
    }
    return sum;
}

// Function to generate a linked list with non-deterministic length
Node *generate_list(int length) {
    Node *head = malloc(sizeof(Node));
    head->value = __VERIFIER_nondet_int();
    head->next = NULL;

    Node *current = head;
    for (int i = 1; i < length; ++i) {
        current->next = malloc(sizeof(Node));
        current = current->next;
        current->value = __VERIFIER_nondet_int();
        current->next = NULL;
    }

    return head;
}

int main() {
    int list_length = __VERIFIER_nondet_int();
    if (list_length <= 0) {
        // Ensure list_length is positive
        list_length = 1;
    }

    Node *list_head = generate_list(list_length);

    // Calculate the sum of all nodes' values
    int sum = calculate_sum(list_head);

    // A constraint to verify: the sum modulo list_length should be less than list_length
    __VERIFIER_assert(sum % list_length < list_length);

    // Properly clean up the allocated memory
    Node *current = list_head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}