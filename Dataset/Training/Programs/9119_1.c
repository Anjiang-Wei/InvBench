#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "custom_verification.c", 7, "reach_error");
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int __VERIFIER_nondet_int(void);

int main() {
    int limit = __VERIFIER_nondet_int();
    if (limit <= 0 || limit > 1000) {
        return 1;
    }

    int accumulator = 0;
    int i, threshold = limit / 2;

    for (i = 0; i < limit; i++) {
        if (i < threshold) {
            accumulator += 2;
        } else {
            accumulator -= 1;
        }
    }

    // Check the condition that should hold true based on the logic
    int expected_sum = threshold * 2 - (limit - threshold);
    __VERIFIER_assert(accumulator == expected_sum);

    return 0;
}