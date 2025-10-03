#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int A = __VERIFIER_nondet_int();
    int B = __VERIFIER_nondet_int();
    int C = __VERIFIER_nondet_int();

    if (A < 0 || B < 0 || C < 0) {
        return 0; // Non-negative constraints
    }

    int sum = 0;
    int product = 1;
    int count = 0;

    while (count < A + B + C) {
        if (count < A) {
            sum += 1;
        } else if (count < A + B) {
            product *= 1;
        } else {
            sum += 1;
            product *= 1;
        }
        count++;
    }

    // Verify some properties at the end
    __VERIFIER_assert(product == 1); // Since product *= 1 doesn't change the value
    __VERIFIER_assert(count == A + B + C);

    return 0;
}