#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    long long a = 1;
    long long b = 1;
    long long c = 2;

    while (n > 0) {
        b = a + b; // b is the next Fibonacci number
        a = b - a; // previous value of b becomes a
        c += b;    // accumulating sum with Fibonacci sequence
        n--;
    }

    __VERIFIER_assert(c > b); // ensure the accumulating sum is always greater than last Fibonacci number calculated

    return 0;
}