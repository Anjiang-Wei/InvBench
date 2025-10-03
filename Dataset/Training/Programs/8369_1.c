/*
  Fibonacci Series - Sum of Even Terms
  Computes the sum of even Fibonacci numbers up to a limit N
*/

#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_sum.c", 8, "reach_error"); }
extern unsigned __VERIFIER_nondet_uint(void);
extern void abort(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    unsigned int N = __VERIFIER_nondet_uint();
    unsigned int sum = 0;
    unsigned int f1 = 0, f2 = 1, next;

    if (N < 2) {
        return 0; // sum is 0 if N is less than 2 as there are no even Fibonacci numbers
    }

    while (1) {
        next = f1 + f2;

        if (next > N) {
            break;
        }

        if (next % 2 == 0) {
            sum += next;
        }

        f1 = f2;
        f2 = next;
    }

    // Ensure that the sum of even Fibonacci numbers is correct upon termination
    __VERIFIER_assert(sum % 2 == 0);

    // Print the results (normally not included in formal verification, but helpful for comprehension)
    printf("Sum of even Fibonacci numbers up to %u is %u\n", N, sum);

    return 0;
}