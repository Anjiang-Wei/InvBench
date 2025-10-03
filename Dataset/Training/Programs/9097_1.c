#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    unsigned int i = 0;
    unsigned int sum = 0;

    // Intended to rotate through a loop modifying `sum`.
    while (i < 10) {
        if (i % 2 == 0) {
            sum += i;
        } else {
            sum -= i;
        }
        i++;
    }

    // Ensure that the sum satisfies certain conditions
    __VERIFIER_assert(sum == -5);

    // Show the value of `sum`.
    printf("The final value of sum is %u\n", sum);

    return 0;
}