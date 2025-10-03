// A C program to compute the Fibonacci sequence sum till a non-deterministically chosen 'n'

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 3, "reach_error"); }
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
    int n, i, fib1 = 0, fib2 = 1, next, sum = 0;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    for (i = 0; i < n; ++i) {
        sum += fib1;
        next = fib1 + fib2;

        // Overflow constraint for next Fibonacci number
        assume_abort_if_not(next >= fib2 && next >= fib1);

        fib1 = fib2;
        fib2 = next;
    }

    // Ensure that the sum of Fibonacci numbers is non-negative
    __VERIFIER_assert(sum >= 0);

    return 0;
}