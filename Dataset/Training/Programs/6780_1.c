#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 5, "reach_error"); }

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
}

int main() {
    int a, b, sum, target, count;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    sum = 0;
    target = __VERIFIER_nondet_int();
    assume_abort_if_not(target >= 0 && target <= 10000);
    count = 0;

    while (sum + a <= target) {
        sum += a;
        count++;
        if (count > 1000) { // avoid infinite loops
            break;
        }

        if (sum + b <= target) {
            sum += b;
            count++;
            if (count > 1000) { // avoid infinite loops
                break;
            }
        }
    }

    // Ensure that final sum does not exceed the target
    __VERIFIER_assert(sum <= target);

    // Output the results for manual inspection
    printf("Final sum: %d, after %d operations.\n", sum, count);

    return 0;
}