/*
  Example C program following learned patterns --
  Sum of first N even numbers where N is a nondeterministic input
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_even_numbers.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR:
        reach_error();
    }
    return;
}

int counter = 0;

int main() {
    int N, current, sum, step;

    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 100); // Constraint for ease of analysis

    current = 0;
    sum = 0;
    step = 0;

    while (step < N) {
        assume_abort_if_not(current % 2 == 0); // It should ensure current is even
        sum += current;
        current += 2;
        step++;

        __VERIFIER_assert(sum == step * (step - 1)); // Check sum of first step even numbers
    }

    // Expected sum of first N even numbers is N * (N - 1)
    __VERIFIER_assert(sum == N * (N - 1));

    return 0;
}