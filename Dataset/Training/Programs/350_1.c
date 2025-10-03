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

// A program simulating managing a bounded stack and checking its integrity
#define STACK_MAX_SIZE 100

typedef struct {
    int data[STACK_MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *stack) {
    stack->top = -1;
}

_Bool push(Stack *stack, int value) {
    if (stack->top < STACK_MAX_SIZE - 1) {
        stack->top++;
        stack->data[stack->top] = value;
        return 1; // success
    }
    return 0; // failure (stack overflow)
}

int pop(Stack *stack) {
    if (stack->top >= 0) {
        int value = stack->data[stack->top];
        stack->top--;
        return value;
    }
    reach_error(); // stack underflow
    return -1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

int main() {
    Stack stack;
    init_stack(&stack);

    int initial_size = __VERIFIER_nondet_int();
    if (initial_size < 0 || initial_size > STACK_MAX_SIZE) {
        return 0;
    }

    // Initialize stack with some values
    for (int i = 0; i < initial_size; i++) {
        push(&stack, __VERIFIER_nondet_int());
    }

    int push_count = __VERIFIER_nondet_int();
    if (push_count < 0) {
        return 0;
    }

    while (push_count > 0) {
        int value = __VERIFIER_nondet_int();
        if (!push(&stack, value)) {
            break; // stop if stack is full
        }
        push_count--;
    }

    while (!is_empty(&stack)) {
        int value = pop(&stack);
        // Perform some operation on the popped value (e.g., check its properties)
        __VERIFIER_assert(value >= -2147483648); // just an example constraint
    }

    return 0;
}