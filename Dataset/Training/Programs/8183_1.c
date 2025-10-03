#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "generated.c", 5, "reach_error");
}

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

#define SIZE 100

// Helper Node Definition for Linked List
struct Node {
    int data;
    struct Node *next;
};

// Function to insert nodes into a linked list
struct Node *insert(struct Node *head, int value) {
    struct Node *newNode = malloc(sizeof(struct Node));
    if (!newNode) {
        abort(); // Check for memory allocation failure
    }
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

// Function to perform some operations on the linked list
void manipulate_list(struct Node *head) {
    struct Node *current = head;
    int sum = 0;
    int prod = 1;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            sum += current->data;
        } else {
            prod *= current->data;
        }
        current = current->next;
    }
    // Ensure sum and product obey certain conditions
    __VERIFIER_assert(sum != 0 || prod != 0);
}

int main() {
    struct Node *list = NULL;
    int i, n;
    n = __VERIFIER_nondet_int();
    if (n < 0 || n > SIZE) {
        return 1;
    }

    // Insert random values into the list
    for (i = 0; i < n; ++i) {
        int value = __VERIFIER_nondet_int();
        list = insert(list, value);
    }

    // Perform operations on the list
    manipulate_list(list);

    // Cleanup: Free the list (to mitigate memory leaks)
    struct Node *current = list;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}