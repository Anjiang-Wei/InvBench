#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_example.c", 3, "reach_error"); }
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
    int x, y, k;

    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    k = __VERIFIER_nondet_int();

    assume_abort_if_not(k > 0 && k <= 100);

    int counter1 = x, counter2 = y;

    // First loop: both counters reach at least 2k
    while (counter1 < 2 * k || counter2 < 2 * k) {
        if (counter1 < 2 * k) {
            counter1++;
        }
        if (counter2 < 2 * k) {
            counter2++;
        }
    }

    // Second loop: reduce the difference to at least k - 1
    while (abs(counter1 - counter2) < k - 1) {
        if (counter1 > counter2) {
            counter1--;
        } else if (counter2 > counter1) {
            counter2--;
        } else {
            counter1++;
            counter2--;
        }
    }

    // Ensure that the difference constraint holds and both are at least k
    __VERIFIER_assert(counter2 >= k);

    return 0;
}