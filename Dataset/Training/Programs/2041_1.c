/* Fibonacci Sequence Verification */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 5, "reach_error"); }
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

int counter = 0;
int main() {
    int n;
    long long a, b, c, i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    a = 0;
    b = 1;
    c = 0;
    i = 0;

    while (counter++ < 5) {
        if (!(i < n)) {
            break;
        }

        c = a + b; // Compute the next Fibonacci number
        a = b;
        b = c;
        i++;
    }

    // Ensure that the sequence and arithmetic are correct for Fibonacci logic
    __VERIFIER_assert(a >= 0);

    return 0;
}