#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "generated_program.c", 5, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int limit = 10;
    int a = 0, b = 1, c;
    int counter = 0;

    // Simple Fibonacci sequence computation with constraint
    while (counter < limit) {
        __VERIFIER_assert(a >= 0); // Assert positivity

        if (counter >= limit) {
            break;
        }

        c = a + b;
        a = b;
        b = c;
        counter++;
    }

    // Verification: The final value of a should be less than a certain threshold

    printf("Fibonacci complete: %d\n", a);
    return 0;
}