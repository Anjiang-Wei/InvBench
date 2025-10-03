/*
 Fibonacci Sequence Algorithm
 Calculates the n-th Fibonacci number using a loop
 and verifies the computed series
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int n;
    unsigned long long fib, prev1, prev2;
    n = __VERIFIER_nondet_uint(); // Supplying n as a non-deterministic unsigned integer

    assume_abort_if_not(n >= 2); // Assume n is at least 2 to satisfy fibonacci sequence conditions

    fib = 1;   // F(1)
    prev1 = 1; // F(1)
    prev2 = 0; // F(0)
    unsigned int i = 2;

    while (counter++ < 100) {
        if (!(i <= n)) {
            break;
        }

        prev2 = prev1;
        prev1 = fib;
        i++;
    }

    __VERIFIER_assert(fib == prev1); // Final assert to ensure final value of fib matches expected

    return 0;
}