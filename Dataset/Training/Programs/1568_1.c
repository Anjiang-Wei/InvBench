#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

#define ARRAY_SIZE 10000

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
        return;
    }
}

int main() {
    int arr[ARRAY_SIZE];
    int i, n, target, count = 0;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= ARRAY_SIZE);

    for (i = 0; i < n; ++i) {
        arr[i] = __VERIFIER_nondet_int();
    }

    target = __VERIFIER_nondet_int();

    for (i = 0; i < n; ++i) {
        if (arr[i] == target) {
            ++count;
        }
    }

    // Checking that the count of target is not greater than the array size
    __VERIFIER_assert(count <= n);

    printf("Target %d found %d times in the array.\n", target, count);
    return 0;
}