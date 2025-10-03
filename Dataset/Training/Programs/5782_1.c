#include <stdlib.h>

/* External functions to simulate environment behavior and verification mechanisms */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 7, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

extern unsigned int __VERIFIER_nondet_uint(); // For generating nondeterministic unsigned integers
extern int __VERIFIER_nondet_int();           // For generating nondeterministic integers

int main() {
    int n = __VERIFIER_nondet_int(); // Total number of elements, assume n > 0
    assume_abort_if_not(n > 0);

    unsigned int sum = 0;
    unsigned int product = 1;
    int *array = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    unsigned int count = 0;

    // Process each element and calculate sum and product
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) { // Check if the number is even
            product *= array[i];
        } else { // Otherwise, it's odd
            sum += array[i];
        }
        count++;
    }

    // Ensure count doesn't exceed provided number of elements
    __VERIFIER_assert(count == n);

    // Further condition checks for results

    free(array); // Free dynamically allocated memory
    return 0;
}