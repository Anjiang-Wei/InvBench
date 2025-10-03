#include <assert.h>
void reach_error(void) { assert(0); }

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern unsigned int __VERIFIER_nondet_uint(void);
extern void assume_abort_if_not(int cond) {
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
    return;
}

// This program computes the factorial of a number in a loop and verifies its correctness.
int main() {
    unsigned int n;
    unsigned int factorial = 1;
    unsigned int i = 1;

    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 5); // Limiting n to ensure safe computation

    // Computing factorial of n
    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify if the computed factorial is correct (for small values)
    if (n == 0 || n == 1) {
    } else if (n == 2) {
    } else if (n == 3) {
    } else if (n == 4) {
    } else if (n == 5) {
        __VERIFIER_assert(factorial == 120);
    }

    return 0;
}