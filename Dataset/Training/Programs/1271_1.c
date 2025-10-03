// A simple program to verify that two non-negative integers x and y
// can be "moved" into a counter by decrementing them, and that
// the total count equals the initial sum x + y.

#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_counter.c", 10, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

int main(void) {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int count = 0;
    int sum0;

    // We constrain x and y to be in [0,1000]
    assume_abort_if_not(x >= 0 && x <= 1000);
    assume_abort_if_not(y >= 0 && y <= 1000);

    // Record the initial sum
    sum0 = x + y;

    // First loop: decrement x into the counter
    while (x > 0) {
        _Bool choice = __VERIFIER_nondet_bool();
        if (choice) {
            // normal step
            x = x - 1;
            count = count + 1;
        } else {
            // an arbitrary no-op iteration
            ;
        }
    }

    // Second loop: decrement y into the counter
    while (y > 0) {
        y = y - 1;
        count = count + 1;
    }

    // At this point, we expect count == sum0
    __VERIFIER_assert(count == sum0);

    return 0;
}