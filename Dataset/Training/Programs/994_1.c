#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 4, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int n, i = 0, product = 1, sum = 0;
    n = __VERIFIER_nondet_int();

    if (n <= 1 || n > 20) {
        return 0; // Constraint to keep the loop bounded
    }
    assume_abort_if_not(n <= 20);

    // Main computational loop
    while (i < n) {
        sum += i;
        product *= (i + 1);
        i++;
    }

    // Verification condition
    __VERIFIER_assert(sum <= product);

    return 0;
}