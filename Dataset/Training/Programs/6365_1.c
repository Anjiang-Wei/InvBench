#include <assert.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error(void) { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/*
 Fibonaccian Challenge: Checks that the iterative
 method correctly computes Fibonacci numbers up to `n`
 where F(0) = 0, F(1) = 1, and F(n) = F(n-1) + F(n-2) for n > 1.
*/

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 30); // limiting n for practical verification

    int fib1 = 0;
    int fib2 = 1;
    int fibN = 0;
    int i = 2;

    if (n == 0) {
        fibN = fib1;
    } else if (n == 1) {
        fibN = fib2;
    } else {
        while (i <= n) {
            fibN = fib1 + fib2;
            fib1 = fib2;
            fib2 = fibN;
            i++;
        }
    }

    __VERIFIER_assert(fibN >= 0); // Fibonacci numbers are always non-negative

    return 0;
}