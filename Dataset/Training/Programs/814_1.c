#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 10, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int();

typedef struct stack {
    int *data;
    int top;
    int capacity;
} Stack;

Stack *create_stack(int capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        abort(); // handle allocation failure
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int *)malloc(capacity * sizeof(int));
    if (stack->data == NULL) {
        free(stack);
        abort(); // handle allocation failure
    }
    return stack;
}

void push(Stack *stack, int item) {
    if (stack->top == stack->capacity - 1) {
        // Stack overflow
        abort();
    }
    stack->data[++stack->top] = item;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        // Stack underflow
        abort();
    }
    return stack->data[stack->top--];
}

int main() {
    int size = 3; // Fixed for verification purposes
    Stack *stack = create_stack(size);

    int i;
    for (i = 0; i < size; i++) {
        int val = __VERIFIER_nondet_int();
        push(stack, val);
    }

    // Check if stack size is maintained correctly
    int count = 0;
    while (stack->top != -1) {
        pop(stack);
        count++;
    }

    // Verify that all elements were popped correctly
    __VERIFIER_assert(count == size);

    // Clean up
    free(stack->data);
    free(stack);

    return 0;
}