#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

struct Node {
    struct Node *next;
    struct Node *prev;
    int value;
};

int main() {
    struct Node *head = NULL;
    struct Node *tail = NULL;

    int threshold = 20;
    int sum_of_squares = 0;
    int counter = 0;

    int n = __VERIFIER_nondet_int();
    if (n <= 0 || n > 100) {
        return 0; // Constraint on n
    }

    while (counter < n) {
        counter++;

        struct Node *newNode = malloc(sizeof(struct Node));
        if (!newNode) {
            abort();
        }

        newNode->value = __VERIFIER_nondet_int();
        newNode->next = NULL;
        newNode->prev = tail;

        if (tail != NULL) {
            tail->next = newNode;
        }
        tail = newNode;

        if (head == NULL) {
            head = newNode;
        }

        if (newNode->value < threshold) {
            sum_of_squares += newNode->value * newNode->value;
        }
    }

    // Assert sum_of_squares is non-negative
    __VERIFIER_assert(sum_of_squares >= 0);

    // Free the nodes
    while (head != NULL) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}