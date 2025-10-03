/*
Fibonacci Sequence Check
This program computes the Fibonacci sequence and verifies properties.
The program ensures that the generated sequence matches the conditions:
F(n) = F(n-1) + F(n-2) for n >= 2
and F(0) = 0, F(1) = 1.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 12, "reach_error"); }

extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int n;
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 50); // Limit for verification tools

    unsigned long long fib_prev = 0, fib_curr = 1, fib_next;
    unsigned long long i = 1;

    // Base cases
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 0;
    }

    // Compute Fibonacci sequence
    while (i < n) {
        fib_next = fib_prev + fib_curr;

        // Verify Fibonacci properties
        __VERIFIER_assert(fib_next - fib_prev - fib_curr == 0);

        fib_prev = fib_curr;
        fib_curr = fib_next;

        i++;
    }

    // Check final property

    return 0;
}