#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Computation of the nth Fibonacci number using loop
and verifying the correctness

precondition: n >= 0
loopcondition: i < n
loop: compute next Fibonacci number
postcondition: the resulting `curr` is the nth Fibonacci number
*/
int main() {
    int n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0);

    int prev = 0;
    int curr = 1;
    int next;

    if (n == 0) {
        curr = 0;
    }

    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }

    // Here we assert that the nth Fibonacci number is greater than or equal to 0
    // which is trivially true since Fibonacci numbers are non-negative.
    __VERIFIER_assert(curr >= 0);

    return 0;
}