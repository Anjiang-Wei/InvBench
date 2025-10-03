#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example4.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
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

int main() {
    int limit = 100;
    int *array = (int *)malloc(sizeof(int) * limit);
    int i;

    // Initialize the array with nondet values and enforce constraints
    for (i = 0; i < limit; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0 && array[i] <= 1000);
    }

    // Sum the elements until the sum exceeds a certain threshold
    int sum = 0;
    int count = 0;
    while (count < limit) {
        sum += array[count];
        count++;
        if (sum > 5000) {
            break;
        }
    }

    // Ensure the loop invariant constraint
    __VERIFIER_assert(sum == 0 || sum > 5000 || count == limit);

    free(array);
    return 0;
}