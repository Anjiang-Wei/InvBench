/*
Fibonacci sequence verifier
This program generates the Fibonacci sequence up to a certain number 'n'
and verifies a simple relationship between consecutive Fibonacci numbers.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }
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
    int n, i, a, b, c;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    // Initialize first two Fibonacci numbers
    a = 0;
    b = 1;

    for (i = 0; i < n; i++) {
        int next = a + b;

        // Verify a simple relationship: it's guaranteed by the definition of the Fibonacci numbers

        // Update Fibonacci numbers
        a = b;
        b = next;

        // Simulate some meaningful constraint: sum of two consecutive numbers is always positive
        __VERIFIER_assert(a + b >= 0);
    }
    return 0;
}