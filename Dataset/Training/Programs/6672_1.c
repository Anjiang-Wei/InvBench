/*
Fibonacci Series with Verification
Compute Fibonacci numbers up to the k-th position
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibo.c", 6, "reach_error"); }
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
    int k;
    unsigned long long a, b, c;
    k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 0 && k <= 47); // limiting k to avoid overflow

    a = 0; // Fib(0)
    b = 1; // Fib(1)
    c = 0; // counter

    while (1) {
        // No explicit loop invariant assertions as requested

        if (!(c < k)) {
            break;
        }

        unsigned long long temp = a;
        a = b;
        b = temp + b;

        c = c + 1;
    }

    // At this point, 'a' should hold Fib(k)
    __VERIFIER_assert(c <= k); // generic check
    return 0;
}