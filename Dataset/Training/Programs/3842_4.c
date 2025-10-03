#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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
    return;
}

extern int __VERIFIER_nondet_int(void);

#define MAX_ITERATIONS 20

int main() {
    int fib1 = 0, fib2 = 1, fib_next;
    int limit;
    int i = 0, counter = 0;

    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit >= 0 && limit <= 1000);

    // Ensure the initial Fibonacci numbers are correct

    while (counter++ < MAX_ITERATIONS && fib2 <= limit) {
        fib_next = fib1 + fib2;
        fib2 = fib_next;

        i++;
    }

    // After the loop, ensure the loop executed correctly up to the limit
    __VERIFIER_assert((i <= MAX_ITERATIONS) && (fib2 > limit || i == MAX_ITERATIONS));

    printf("Fibonacci sequence computed up to %d iterations or until value > %d.\n", i, limit);

    return 0;
}