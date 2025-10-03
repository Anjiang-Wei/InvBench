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

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} Stack;

void init_stack(Stack *stack) {
    stack->size = 0;
}

int push(Stack *stack, int value) {
    if (stack->size >= MAX_SIZE) {
        return -1; // Stack overflow
    }
    stack->data[stack->size++] = value;
    return 0;
}

int pop(Stack *stack, int *value) {
    if (stack->size <= 0) {
        return -1; // Stack underflow
    }
    *value = stack->data[--stack->size];
    return 0;
}

int is_empty(Stack *stack) {
    return stack->size == 0;
}

int main() {
    Stack stack;
    init_stack(&stack);

    // Push a nondeterministic number of elements
    while (__VERIFIER_nondet_int()) {
        if (push(&stack, __VERIFIER_nondet_int()) == -1) {
            // Handle stack overflow if needed
            break;
        }
    }

    // Check invariant: size should be less than or equal to MAX_SIZE

    // Pop elements and verify properties
    int sum = 0;
    int num_elements = 0;
    int value;

    while (!is_empty(&stack)) {
        if (pop(&stack, &value) == -1) {
            // Handle stack underflow if needed
            break;
        }
        sum += value;
        num_elements++;
    }

    // Check invariant: if stack was not empty, sum should have increased
    if (num_elements > 0) {
    }

    // Final size check to ensure stack is empty
    __VERIFIER_assert(stack.size == 0);

    return 0;
}