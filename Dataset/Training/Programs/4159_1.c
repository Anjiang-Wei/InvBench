extern void abort(void);
#include <assert.h>

/* Error reporting function */
void reach_error() { assert(0); }

/* Nondeterministic integer generator */
extern int __VERIFIER_nondet_int(void);

/* Assume-or-abort convenience */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Verification assertion */
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main(void) {
    /* Choose a bound k between 0 and 30 */
    int k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 0 && k <= 30);

    int fib_prev, fib_curr, temp;

    /* Compute the k-th Fibonacci number */
    if (k == 0) {
        fib_curr = 0;
    } else {
        fib_prev = 0;
        fib_curr = 1;
        int i = 1;
        while (i < k) {
            temp = fib_prev + fib_curr;
            fib_prev = fib_curr;
            fib_curr = temp;
            i = i + 1;
        }
    }

    /* Assert the well-known bound: Fib(k) < 2^k */
    int bound = 1 << k;
    __VERIFIER_assert(fib_curr < bound);

    return 0;
}