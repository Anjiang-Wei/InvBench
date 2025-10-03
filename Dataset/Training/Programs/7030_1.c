#include <stddef.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "unique_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    // k represents some upper bound control
    int k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 1 && k <= 1000);

    // Initialize starting points
    long long sum = 0;
    int i = 1, j = 1;

    // Outer loop controlled by nondet value `k`
    while (i < k) {
        // Inner loop whose behavior depends on the outer loop
        while (j <= i * 2) {
            sum += j;
            j++;
        }
        // Ensure unique condition
        __VERIFIER_assert(sum > 0);
        i++;
    }

    // Verify the result (the condition should be logically inferred)

    return 0;
}