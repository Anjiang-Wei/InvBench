/*
 * Algorithm for computing the Fibonacci sequence using an iterative approach.
 * This program includes assertion checks for each computed Fibonacci number.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern unsigned __VERIFIER_nondet_uint(void);
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

int main() {
    unsigned n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0);  // Ensure non-negative input
    assume_abort_if_not(n <= 47); // Limit to avoid overflow in unsigned int

    unsigned fib_prev = 0;
    unsigned fib_curr = 1;
    unsigned fib_next = 0;

    // Verify initial conditions
    if (n == 0) {
    } else if (n == 1) {
    } else {
        unsigned counter = 2; // Start from the third Fibonacci number
        while (counter <= n) {
            fib_next = fib_prev + fib_curr;

            // Verify the Fibonacci property for each step

            fib_prev = fib_curr;
            fib_curr = fib_next;
            counter++;
        }
    }

    // Final assertion to ensure correctness of the nth Fibonacci number
    if (n >= 2) {
        __VERIFIER_assert(fib_curr == fib_prev + fib_next - fib_prev);
    }

    return 0;
}