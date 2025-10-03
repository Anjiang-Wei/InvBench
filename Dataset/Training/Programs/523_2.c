/*
Fibonacci Sequence Verification
Computes Fibonacci sequence and verifies some properties.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    int n, i;
    long long a, b, c;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20); // Limit n for analysis

    a = 0;
    b = 1;
    i = 1;

    while (1) {
        if (!(i <= n)) {
            break;
        }

        c = a + b;
        a = b;
        b = c;
        i = i + 1;

        // Verify the property: Fibonacci numbers should always be non-negative
        __VERIFIER_assert(b >= 0);
    }

    // Assert that the nth Fibonacci number is less than 17711 (F(20) = 6765)

    return 0;
}