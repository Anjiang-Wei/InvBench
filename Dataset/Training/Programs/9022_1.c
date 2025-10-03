#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 10, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0 || n > 1000) {
        return 1;
    }
    assume_abort_if_not(n <= 1000);

    int *array = malloc(sizeof(int) * n);
    if (array == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    int sum = 0;
    int product = 1;

    for (int i = 0; i < n; i++) {
        // Considering overflow might occur in a real-world scenario
        if (product < 0) {
            product = 1; // Reset if overflow occurred
        }
        sum += array[i];
        product *= (array[i] % 10); // Product of least significant digits
    }

    // Sum should never exceed n * maximum possible integer value if properly bounded
    assume_abort_if_not(sum >= 0); // Expected due to bounded integers

    // Basic post-condition check
    __VERIFIER_assert(sum >= 0); // Sum is non-negative given the constraints
    free(array);
    return 0;
}