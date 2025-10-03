#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Helper functions to simulate verification environment */
void abort(void);
void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 7, "reach_error"); }
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

/* Random number generation within a range */
int __VERIFIER_nondet_int(void) {
    return rand() % 256;
}

int main() {
    /* Initialize random seed */
    srand(time(NULL));

    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 2); // Ensure that n is meaningful for the constraints of this program

    int even_count = 0; // Count of even numbers
    int i = 0;

    /* Array to store series of integers */
    int arr[n];

    for (i = 0; i < n; ++i) {
        arr[i] = __VERIFIER_nondet_int();
    }

    /* Loop to check constraints and perform computations */
    for (i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            even_count++;
        }
    }

    __VERIFIER_assert(even_count <= n); // Ensure count of even numbers is not more than n

    printf("Total even numbers: %d\n", even_count);

    return 0;
}