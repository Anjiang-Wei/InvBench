#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * This program simulates a stack with push and pop operations using a linked list.
 * The stack supports a limited size, ensuring it does not grow endlessly.
 * We will assert that the number of push operations never exceeds the specified stack limit.
 */

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Stack {
    struct Node *top;
    int limit;
    int count;
} Stack;

void push(Stack *stack, int value) {
    if (stack->count < stack->limit) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->value = value;
        newNode->next = stack->top;
        stack->top = newNode;
        stack->count++;
    }
}

void pop(Stack *stack) {
    if (stack->top != NULL) {
        Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->count--;
    }
}

int main() {
    const int STACK_LIMIT = 10;

    Stack stack;
    stack.top = NULL;
    stack.limit = STACK_LIMIT;
    stack.count = 0;

    int operation;
    // Perform a series of random push and pop operations
    while (__VERIFIER_nondet_bool()) {
        operation = __VERIFIER_nondet_int();
        if (operation % 2 == 0) {
            push(&stack, __VERIFIER_nondet_int());
        } else {
            pop(&stack);
        }
        // Ensure the number of elements in the stack never exceeds the limit
        __VERIFIER_assert(stack.count <= STACK_LIMIT);
    }

    // Free the stack
    while (stack.top != NULL) {
        pop(&stack);
    }

    return 0;
}