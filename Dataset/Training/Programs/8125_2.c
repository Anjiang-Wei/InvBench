#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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

int counter = 0;

int main() {
    int a = 1;
    int b = __VERIFIER_nondet_int();
    int factorial = 1;
    assume_abort_if_not(b >= 0 && b <= 10); // Limit input to a reasonable range

    // Calculate factorial of 'b'
    while (counter++ < b) {
        factorial *= a; // Incremental multiplication
        a += 1;         // Move to the next integer
    }

    // Factorial verification assertion
    if (b > 0) {
        int verify_factorial = 1;
        int verify_a = 1;
        while (verify_a <= b) {
            verify_factorial *= verify_a;
            verify_a += 1;
        }
    } else {
        __VERIFIER_assert(factorial == 1); // Factorial of 0 is 1
    }

    printf("The factorial of %d is %d\n", b, factorial);
    return 0;
}