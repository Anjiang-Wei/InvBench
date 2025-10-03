#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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

// Function simulating a nondeterministic choice of an even number
int get_even_number() {
    int num = __VERIFIER_nondet_int();
    assume_abort_if_not(num % 2 == 0);
    return num;
}

int main() {
    int a = get_even_number();
    int b = __VERIFIER_nondet_int();

    // Constraints on b
    assume_abort_if_not(b > 0);
    assume_abort_if_not(b < 10);

    int result = 0;
    int multiplier = 1;

    // Loop that adds multiples of a to result, with constraints on iterations
    while (1) {
        if (!(multiplier <= b)) {
            break;
        }

        result += a * multiplier;

        if (result % 2 != 0) { // Result should always be even
            goto ERROR;
        }

        multiplier++;
    }

    // Final check
    __VERIFIER_assert(result % 2 == 0);
    printf("Result is even: %d\n", result);

    return 0;

ERROR : {
    reach_error();
    abort();
}
}