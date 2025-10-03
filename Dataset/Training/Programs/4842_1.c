#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", __LINE__, "reach_error"); }

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
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

volatile int counter = 0;

int main(void) {
    int a, b, sum, diff;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Ensure valid input ranges
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    sum = a + b;
    diff = a - b;

    while (counter++ < 50) {
        // Perform some meaningful operations
        if (sum == diff) {
            sum += 5;
        } else if (sum < diff) {
            sum *= 2;
        } else {
            diff += 3;
        }

        // Random decision to break loop
        if ((sum + diff) % 10 == 0) {
            break;
        }
    }

    __VERIFIER_assert((sum + diff) >= 0);
    return 0;
}