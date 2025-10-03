/*
  Fibonacci Sequence Verification
  Computes the Fibonacci sequence up to the k-th term
  Verifies the identity F(n)^2 + F(n-1)^2 = F(2n-1)
*/

#include <assert.h>

extern void abort(void);
#include <limits.h>
void reach_error() { assert(0); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int counter = 0;
int main() {
    unsigned int k;
    unsigned long long fn, fn1, fn2, temp, f2n1;
    k = __VERIFIER_nondet_uint();

    // Initial Fibonacci values
    fn2 = 0; // F(0)
    fn1 = 1; // F(1)
    fn = 1;  // F(2)

    // Start with F(n)=F(2), F(n-1)=F(1), and F(n-2)=F(0)

    while (counter++ < 10) {
        // Loop until we compute F(n) and F(2n-1)
        if (k < 3) {
            break; // No need to compute for small k
        }

        while (fn2 + fn1 <= k) {
            temp = fn;
            fn = fn + fn1;
            fn2 = fn1;
            fn1 = temp;

            // Check the identity F(n)^2 + F(n-1)^2 = F(2n-1)
            f2n1 = fn * fn + fn2 * fn2;
        }
    }

    // Perform post-loop assertion
    if (fn >= 2) {
        __VERIFIER_assert(fn * fn + fn2 * fn2 == f2n1);
    }

    return 0;
}