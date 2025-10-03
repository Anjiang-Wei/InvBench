#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int();
_Bool __VERIFIER_nondet_bool();

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    if (x < 0 || y < 0) {
        return 0;
    }

    // Sum variable to compute the total in the loop
    int sum = 0;
    int factor = 1;

    while (x > 0 && y > 0) {
        _Bool choice = __VERIFIER_nondet_bool();
        if (choice) {
            sum += factor * y;
            x--;
        } else {
            sum += factor * x;
            y--;
        }
        factor *= 2; // Double up the factor each time
    }

    // We expect sum to be non-negative if initial values of x and y are non-negative

    // By the end, either x or y should be zero
    __VERIFIER_assert(x == 0 || y == 0);

    printf("Final sum is %d\n", sum);
    return 0;
}