#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sample.c", 5, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // Or enforce another meaningful constraint

    int odd_sum = 0;
    int even_sum = 0;

    // Sum computation logic
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) { // Even
            even_sum += i;
        } else { // Odd
            odd_sum += i;
        }
    }

    __VERIFIER_assert((n % 2 == 0 && (even_sum > odd_sum)) || (n % 2 != 0 && (odd_sum > even_sum)));

    return 0;
}