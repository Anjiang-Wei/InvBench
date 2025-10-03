/*
    Fibonacci Sequence Computation
    Computes the nth Fibonacci number iteratively
    with verification of the relation F(n) = F(n-1) + F(n-2).
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    unsigned int n;
    unsigned int a, b, fib, i;

    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 2 && n <= 30); // Considering the Fibonacci sequence within a reasonable range

    a = 0;       // F(0)
    b = 1;       // F(1)
    fib = a + b; // F(2)
    i = 2;

    while (1) {
        __VERIFIER_assert(fib == a + b); // Verify if F(n) = F(n-1) + F(n-2)

        if (!(i < n)) {
            break;
        }

        a = b;
        b = fib;
        fib = a + b;
        i++;
    }
}