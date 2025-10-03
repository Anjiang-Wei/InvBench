#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int A = __VERIFIER_nondet_int();
    int B = __VERIFIER_nondet_int();

    assume_abort_if_not(B >= 1);
    assume_abort_if_not(A >= 0 && A <= 100);

    int sum = 0;
    int count = 0;

    while (__VERIFIER_nondet_bool()) {
        if (A >= B) {
            sum += B;
            A -= B;
            count++;
        } else {
            sum += A;
            A = 0;
        }
    }

    // Verify final condition
    __VERIFIER_assert(sum >= 0 && sum <= 100 + B);

    return 0;
}