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
    ERROR : { reach_error(); }
    }
    return;
}

int complex_computation(int input, int *state) {
    int result = 0;
    if (*state < 10) {
        result = input * 2;
        *state += 1;
    } else {
        result = input / 2;
        *state -= 1;
    }
    return result;
}

int main() {
    int state = 5;
    int iterations = 10;
    int result = 0;

    while (iterations > 0) {
        int input = __VERIFIER_nondet_int();
        assume_abort_if_not(input >= 1 && input <= 100);

        result = complex_computation(input, &state);

        if (result < 0) {
            break;
        }

        iterations--;
    }

    __VERIFIER_assert(state >= 0 && state <= 10);
    printf("Final state: %d\n", state);
    return 0;
}