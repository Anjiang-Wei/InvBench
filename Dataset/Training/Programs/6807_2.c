#include <assert.h>
#include <limits.h>

// External functions for verification and nondeterminism
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "complex_algorithm.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

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

#define MAX_SIZE 50

// Complex computational logic involving arrays and constraints
int main() {
    int arr[MAX_SIZE];
    int i, sum = 0, product = 1;
    int threshold = __VERIFIER_nondet_int();

    // Array initialization with constraints
    for (i = 0; i < MAX_SIZE; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= 0 && arr[i] <= 100); // values constrained between 0 and 100
    }

    // Verification assertions

    // Computation loop
    while (i < MAX_SIZE) {
        sum += arr[i];
        product *= arr[i] == 0 ? 1 : arr[i]; // avoid multiplication by zero
        __VERIFIER_assert(sum <= threshold); // sum should not exceed threshold
        if (__VERIFIER_nondet_bool()) {      // nondeterministic choice
            i++;
        } else {
            break;
        }
    }

    // Post-loop verification

    // Additional logic involving a secondary loop
    int j = 0;
    while (j < MAX_SIZE) {
        if (__VERIFIER_nondet_bool()) { // selective processing
            arr[j] = (arr[j] * 2) % 101;
        }
        j++;
    }

    // Final assertions
    for (i = 0; i < MAX_SIZE; i++) {
    }

    return 0;
}