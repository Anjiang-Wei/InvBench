#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }
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
}

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *create_list(int size) {
    if (size <= 0) {
        return NULL;
    }
    Node *head = malloc(sizeof(Node));
    head->value = 0;
    Node *current = head;
    for (int i = 1; i < size; ++i) {
        current->next = malloc(sizeof(Node));
        current = current->next;
        current->value = i;
    }
    current->next = NULL;
    return head;
}

int sum_list(Node *head) {
    int sum = 0;
    while (head != NULL) {
        sum += head->value;
        head = head->next;
    }
    return sum;
}

int product_of_sums(int a, int b) {
    return a * b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000); // assuming a reasonable list size for demonstration

    Node *list1 = create_list(n);
    Node *list2 = create_list(n);

    int sum1 = sum_list(list1);
    int sum2 = sum_list(list2);

    int product_sum = product_of_sums(sum1, sum2);

    __VERIFIER_assert(product_sum == sum1 * sum2);

    // Free allocated memory
    Node *tmp;
    while (list1 != NULL) {
        tmp = list1;
        list1 = list1->next;
        free(tmp);
    }
    while (list2 != NULL) {
        tmp = list2;
        list2 = list2->next;
        free(tmp);
    }

    return 0;
}