#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function to simulate nondeterministic integer input
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int calculate_fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int limit = __VERIFIER_nondet_int(); // Nondeterministic limit for the Fibonacci calculation
    assume_abort_if_not(limit >= 0 && limit <= 10);

    int fib = calculate_fibonacci(limit);

    // Verification condition: We assume the 10th Fibonacci number to verify the logic
    // The 10th Fibonacci number is 55, since the max limit here is 10.
    if (limit == 10) {
        __VERIFIER_assert(fib == 55);
    }

    printf("Fibonacci(%d) = %d\n", limit, fib);

    return 0;
}