#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

/* Verification function to cause failure if the condition is false */
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
    int i = 0;
    int a = 0;
    int b = 0;
    int target = __VERIFIER_nondet_int();

    // Initialize the target and ensure it's positive
    if (target <= 0) {
        target = 10;
    }

    // Computational logic with constraints
    while (i < target) {
        i++;
        a = a + 2;
        b = b + 3;

        // Ensure b is always greater than a after each increment
    }

    // Final check after loop completion
    __VERIFIER_assert(b == 3 * target);

    printf("a: %d, b: %d, target: %d\n", a, b, target);

    return 0;
}