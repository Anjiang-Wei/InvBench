#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int calculate_checksum(int array[], int n) {
    int checksum = 0;
    int i;
    for (i = 0; i < n; i++) {
        checksum += array[i];
    }
    return checksum % 256; // Modulo operation to simulate checksum behavior
}

int multiply_integers(int a, int b) {
    if (a > 1000 || b > 1000) {
        return -1; // Arbitrary constraint, return an error code
    }
    return a * b;
}

int main() {
    int n, result, c, checksum;
    int data[10];

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    // Initialization and computation loop
    for (c = 0; c < n; c++) {
        data[c] = c + 1;
    }

    // Checksum calculation
    checksum = calculate_checksum(data, n);

    // Perform calculations with arbitrary constraints
    result = multiply_integers(checksum, n);

    // Verification with constraints
    if (result != -1) {
        if (result % n == 0) {
            printf("Result is a multiple of %d\n", n);
        } else {
            printf("Result is not a multiple of %d\n", n);
        }
    } else {
        printf("Multiplication constraint violated.\n");
    }

    // Post-condition check
    __VERIFIER_assert(result != -1);

    return 0;

ERROR : {
    reach_error();
    abort();
}
    return 1;
}