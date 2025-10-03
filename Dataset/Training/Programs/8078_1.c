#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern double __VERIFIER_nondet_double(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int length;
} LinkedList;

LinkedList *create_list(int initial_length) {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->length = 0;

    for (int i = 0; i < initial_length; i++) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        if (new_node == NULL) {
            abort(); // Memory allocation failed
        }
        new_node->data = __VERIFIER_nondet_int();
        new_node->next = list->head;
        list->head = new_node;
        list->length++;
    }
    return list;
}

void insert_node(LinkedList *list, int value, int position) {
    if (position < 0 || position > list->length) {
        return;
    }
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        abort(); // Memory allocation failed
    }
    new_node->data = value;

    if (position == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node *current = list->head;
        for (int i = 0; i < position - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    list->length++;
}

int calculate_sum_of_squares(LinkedList *list) {
    int sum = 0;
    Node *current = list->head;
    while (current != NULL) {
        sum += current->data * current->data;
        current = current->next;
    }
    return sum;
}

void destroy_list(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current->next;
        free(current);
        current = temp;
    }
    free(list);
}

int main() {
    int initial_length = __VERIFIER_nondet_int();
    assume_abort_if_not(initial_length >= 1 && initial_length <= 10);
    LinkedList *list = create_list(initial_length);

    int k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 1 && k <= 5);

    for (int i = 0; i < k; i++) {
        int value = __VERIFIER_nondet_int();
        int position = __VERIFIER_nondet_int();
        assume_abort_if_not(position >= 0 && position <= list->length);

        insert_node(list, value, position);
    }

    int sum_of_squares = calculate_sum_of_squares(list);
    __VERIFIER_assert(sum_of_squares >= 0);

    destroy_list(list);
    return 0;
}