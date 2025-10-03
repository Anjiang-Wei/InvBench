/*
  Fibonacci Sequence using Iterative Method
  Calculate the nth Fibonacci number.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 7, "reach_error"); }
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
    n = __VERIFIER_nondet_int();

    // Constraints for nondeterministic variable
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 20); // Arbitrarily chosen bound

    int a = 0, b = 1;
    int c = 0;
    int i = 0;

    while (i < n) {
        c = a + b;
        a = b;
        b = c;
        i = i + 1;
    }

    // Post condition (for example verifying the simple invariant sum up to nth number)
    __VERIFIER_assert(a <= 10946); // Fibonacci(20) = 10946

    return 0;
}