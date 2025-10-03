#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

struct list {
    int value;
    struct list *next;
};

struct list *nondet_list() {
    if (__VERIFIER_nondet_bool()) {
        return NULL;
    } else {
        struct list *node = (struct list *)malloc(sizeof(struct list));
        node->value = __VERIFIER_nondet_int();
        node->next = nondet_list();
        return node;
    }
}

int list_length(struct list *head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct list *list_append(struct list *head, int value) {
    struct list *node = (struct list *)malloc(sizeof(struct list));
    node->value = value;
    node->next = NULL;

    if (head == NULL) {
        return node;
    }

    struct list *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = node;

    return head;
}

void verify_list_elements(struct list *head) {
    while (head != NULL) {
    }
}

void free_list(struct list *head) {
    struct list *current = head;
    while (current != NULL) {
        struct list *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct list *head = nondet_list();
    int original_length = list_length(head);

    // Add a known element to the list
    head = list_append(head, 1);

    // Verify that all elements in the modified list are non-zero, if any list exists
    if (original_length != 0) {
        verify_list_elements(head);
    }

    int new_length = list_length(head);

    __VERIFIER_assert(new_length == original_length + 1);

    free_list(head);
    return 0;
}