#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern unsigned int __VERIFIER_nondet_uint(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

typedef struct TNode {
    int value;
    struct TNode *left;
    struct TNode *right;
} Node;

Node *create_tree(int depth) {
    if (depth == 0 || __VERIFIER_nondet_int() == 0) {
        return NULL;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    __VERIFIER_assert(node != NULL);
    node->value = __VERIFIER_nondet_int();
    node->left = create_tree(depth - 1);
    node->right = create_tree(depth - 1);
    return node;
}

int sum_tree(Node *node) {
    if (node == NULL) {
        return 0;
    }
    return node->value + sum_tree(node->left) + sum_tree(node->right);
}

void free_tree(Node *node) {
    if (node == NULL) {
        return;
    }
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

void check_sum_condition(Node *root, int max_depth) {
    int expected_sum = 0;
    Node *node = root;
    int depth = 0;
    while (node != NULL && depth < max_depth) {
        expected_sum += node->value;
        node = node->left; // Traverse the leftmost path.
        depth++;
    }
    int actual_sum = sum_tree(root);
}

int main() {
    int max_depth = 5;
    Node *root = create_tree(max_depth);

    check_sum_condition(root, max_depth);

    free_tree(root);

    return 0;
}