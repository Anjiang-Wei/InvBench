#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "find_product_closest.c", 9, "reach_error"); }
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
    int target, limit;
    target = __VERIFIER_nondet_int();
    assume_abort_if_not(target > 0 && target < 1000);

    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0 && limit < 100);

    int i, j;
    int closest_product = 0;
    int a = 0, b = 0;

    for (i = 1; i <= limit; i++) {
        for (j = i; j <= limit; j++) {
            int product = i * j;

            if (product > target && product < closest_product) {
                break;
            }

            if (product >= closest_product && product <= target) {
                closest_product = product;
                a = i;
                b = j;
            }
        }
    }

    __VERIFIER_assert(a * b <= target);
    printf("Closest product: %d using a: %d and b: %d\n", closest_product, a, b);
    return 0;
}