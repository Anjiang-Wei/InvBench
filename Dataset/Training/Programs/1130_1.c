#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "new_program.c", 5, "reach_error");
}
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
    int target, sum = 0, number;
    int counter = 0, limit = __VERIFIER_nondet_int();

    target = __VERIFIER_nondet_int();
    assume_abort_if_not(target >= 10 && target <= 100);
    assume_abort_if_not(limit >= 5 && limit <= 20);

    while (counter < limit) {
        number = __VERIFIER_nondet_int();

        // Assume number is within an explicit range to control nondet behavior
        assume_abort_if_not(number >= 1 && number <= 10);

        // Simulate some computation
        sum += number;

        if (sum > target) {
            sum -= number; // Undo last addition if it exceeds target
        }

        counter++;
    }

    // Check a condition related to sum and iterations
    __VERIFIER_assert(sum <= target);

    printf("Final sum: %d\n", sum);
    return 0;
}