#include <assert.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100);

    int fib_prev = 0;
    int fib_current = 1;
    int i = 1;

    while (i < n) {
        int fib_next = fib_prev + fib_current;

        // Propagate forward for next iteration
        fib_prev = fib_current;
        fib_current = fib_next;

        i = i + 1;
    }

    // At this point, fib_current should be the n-th Fibonacci number.
    // We add a generic assertion at the end, without specifying its invariant or expected condition.
    __VERIFIER_assert(fib_current >= 0 && fib_prev >= 0);

    return 0;
}