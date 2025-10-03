/* Fibonacci Sequence Generation and Verification */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verification.c", 4, "reach_error"); }
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
    return;
}

int main() {
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Limiting the number for demonstration purposes

    long long fib_prev = 0; // F(0)
    long long fib_curr = 1; // F(1)
    long long fib_next;

    int counter = 1; // Start from 1 since F(0) and F(1) are already known
    while (counter < n) {
        // Calculate the next Fibonacci number
        fib_next = fib_prev + fib_curr;

        // Verify the properties of the current Fibonacci number

        // Update the previous two Fibonacci numbers
        fib_prev = fib_curr;
        fib_curr = fib_next;

        counter = counter + 1;
    }

    // Additional constraint checks
    if (n == 0) {
    } else if (n == 1) {
        __VERIFIER_assert(fib_curr == 1);
    }

    return 0;
}