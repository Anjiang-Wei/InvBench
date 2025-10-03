#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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
    return;
}

int main() {
    int n, i, sum = 0, factor = 2;
    n = __VERIFIER_nondet_int();

    // Input assumption
    assume_abort_if_not(n > 0 && n < 1000);

    for (i = 1; i <= n; i++) {
        sum += i * factor; // some meaningful computation
    }

    // Verify that the transformed sum is an even number
    __VERIFIER_assert(sum % 2 == 0);

    if (sum > 0) {
        printf("Sum is positive\n");
    } else {
        printf("Sum is non-positive\n");
    }

    return 0;
}