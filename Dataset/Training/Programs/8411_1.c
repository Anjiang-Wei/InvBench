#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
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
    int A, B, C, D;
    A = __VERIFIER_nondet_int();
    B = __VERIFIER_nondet_int();
    C = __VERIFIER_nondet_int();

    assume_abort_if_not(A > 0 && B > 0);
    assume_abort_if_not(C > A);

    D = A + B;
    int result = 0;
    int i = 0;

    // Loop with meaningful computation and constraints
    while (i < 10) {
        D += i;
        if (D > C) {
            result++;
            D = D - A;
        }
        i++;
    }

    // Final check
    __VERIFIER_assert(result >= 0 && D >= 0);

    // Final output to interact with the environment
    printf("Result: %d\n", result);
    printf("Final D: %d\n", D);
    return 0;
}