#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * This program checks if a linked list with unique integer values
 * contains a specific target value using a loop. If the target is
 * found, it verifies an assertion.
 */

typedef struct node {
    int data;
    struct node *next;
} *SLL;

SLL node_create(int data) {
    SLL temp = (SLL)malloc(sizeof(struct node));
    if (NULL == temp) {
        exit(1);
    }
    temp->next = NULL;
    temp->data = data;
    return temp;
}

SLL sll_create_with_unique_values(int len, int start_value) {
    SLL head = NULL;
    for (int i = 0; i < len; ++i) {
        SLL new_head = node_create(start_value + i);
        new_head->next = head;
        head = new_head;
    }
    return head;
}

void sll_find_and_verify_target(SLL head, int target) {
    SLL current = head;
    int found = 0;
    while (current != NULL) {
        if (current->data == target) {
            found = 1;
            break;
        }
        current = current->next;
    }
    __VERIFIER_assert(found == 1); // Verify that target value must be found
}

int main() {
    const int len = 5;
    const int start_value = 10;
    const int target_value = 12; // Known to exist in the list

    SLL list = sll_create_with_unique_values(len, start_value);

    // Call the function to find the target value
    sll_find_and_verify_target(list, target_value);

    // Free the allocated list
    SLL current = list;
    while (current != NULL) {
        SLL next = current->next;
        free(current);
        current = next;
    }

    return 0;
}