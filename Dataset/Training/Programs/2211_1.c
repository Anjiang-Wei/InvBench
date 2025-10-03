// Program to compute the sum of the first n natural numbers
// and to verify the formula 2*s == n*(n+1) by an automated tool

#include <stdio.h>

// Declarations for the verification environment
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_n.c", 10, "reach_error");
}
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    // We bound n so the loop is finite for verification
    assume_abort_if_not(n >= 0 && n <= 20);

    long long s = 0; // running sum
    int i = 1;       // next integer to add
    int counter = 0;

    // Invariant (implicitly checked): 2*s == (i-1)*i
    while (counter++ < 50) {
        // Check the invariant before each iteration
        __VERIFIER_assert(2 * s == (long long)(i - 1) * i);

        if (!(i <= n)) {
            break;
        }

        s += i;
        i++;
    }

    // After the loop, we must have summed 1+2+...+n into s

    return 0;
}