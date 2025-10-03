/*
Fibonacci Sequence Verification
Verifies the properties of Fibonacci numbers.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
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
    long long fn_1, fn_2, fn, i;

    // Non-deterministically choose n
    n = __VERIFIER_nondet_int();
    // Assume n is non-negative
    assume_abort_if_not(n >= 0);

    // Base cases:
    fn_2 = 0; // F(0)
    fn_1 = 1; // F(1)

    if (n == 0) {
        fn = fn_2;
    } else if (n == 1) {
        fn = fn_1;
    } else {
        fn = 0; // This will be updated in the loop
        i = 2;

        while (counter++ < 100) {
            if (!(i <= n)) {
                break;
            }

            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
            i++;
        }
    }

    // Final assertions to check Fibonacci identities
    // Known properties for any F(n): F(n) >= 0 and F(n) = F(n-1) + F(n-2)
    __VERIFIER_assert(fn >= 0);

    return 0;
}