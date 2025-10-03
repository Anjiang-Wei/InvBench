/*
Fibonacci Sequence
Computes the nth Fibonacci number using iteration
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-ll.c", 9, "reach_error"); }
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
    long long fib, a, b, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 50);

    a = 0;
    b = 1;
    fib = n < 2 ? n : 0;
    i = 2;

    while (i <= n) {
        fib = a + b;
        a = b;
        b = fib;
        i++;
    }

    __VERIFIER_assert(fib == (n == 0 ? 0 : (n == 1 ? 1 : (a + b - a))));
    return 0;
}