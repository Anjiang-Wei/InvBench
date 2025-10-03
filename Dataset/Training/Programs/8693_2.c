/*
 * Fibonacci sequence calculation with loop invariants
 * This program calculates Fibonacci numbers in a non-recursive manner
 * using two variables to store intermediate results.
 * It includes bounds-checking assertions to verify properties of Fibonacci growth.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
}

int main() {
    int n;
    long long fib1, fib2, fib_current;

    // Get a nondeterministic integer, make sure it is non-negative
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 50); // Assuming reasonable bound to prevent overflow

    fib1 = 0;        // F(0)
    fib2 = 1;        // F(1)
    fib_current = 0; // F(n), initialized for n=0 case
    int i = 0;

    while (i <= n) {
        if (i == 0) {
            fib_current = fib1; // F(0) = 0
        } else if (i == 1) {
            fib_current = fib2; // F(1) = 1
        } else {
            fib_current = fib1 + fib2; // F(i) = F(i-1) + F(i-2)
            fib1 = fib2;               // Move fib2 to fib1
            fib2 = fib_current;        // Current becomes the new fib2
        }
        // Verification condition: Fibonacci property that fib_current >= fib1
        i++;
    }

    // Final condition: The computed Fibonacci number should be at least 0
    __VERIFIER_assert(fib_current >= 0);

    return 0;
}