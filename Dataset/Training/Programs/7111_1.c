#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int i = 0;
    int j = 0;
    int sum = 0;

    assume_abort_if_not(m > 0);
    assume_abort_if_not(n > 0);
    assume_abort_if_not(n < 5);

    while (i < m) {
        i++;

        if (__VERIFIER_nondet_bool()) {
            sum += 100;
        } else {
            sum += 50;
        }
    }

    while (j < n) {
        j++;
        if (__VERIFIER_nondet_bool()) {
            sum += 200;
        } else {
            sum += 100;
        }
    }

    __VERIFIER_assert(sum > (m + n) * 50);

    return 0;
}