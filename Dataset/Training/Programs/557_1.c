#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "linear_search.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int size = 10;
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = __VERIFIER_nondet_int();
    int found = 0;

    assume_abort_if_not(target >= 0 && target < 10);

    for (int i = 0; i < size; i++) {
        if (array[i] == target) {
            found = 1;
            break;
        }
    }

    // Verify that if the target is found, then it is in the array
    if (found) {
        int verification = 0;
        for (int i = 0; i < size; i++) {
            if (array[i] == target) {
                verification = 1;
                break;
            }
        }
        __VERIFIER_assert(verification == 1);
    }

    return 0;
}