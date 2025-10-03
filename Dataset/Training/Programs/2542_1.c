#include <stdio.h>
#include <stdlib.h>

// This function simulates a nondeterministic choice
int __VERIFIER_nondet_int() {
    return rand() % 10; // returns a random number between 0 and 9
}

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "example.c", 15, "reach_error");
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
    int x = 0;
    int sum = 0;
    int target = 50;

    while (x < target) {
        int step = __VERIFIER_nondet_int(); // nondeterministic step size
        if (x + step > target) {
            step = target - x; // ensure x does not exceed target
        }
        x += step;
        sum += step;
    }

    // Verifying that the sum of the steps equals the target
    __VERIFIER_assert(x == target);

    printf("Sum reached the target value of %d\n", target);
    return 0;
}