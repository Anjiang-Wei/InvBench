#include <stdio.h>
#include <stdlib.h>

/*
  Target Sum Finder
  This program tries to find a combination of integers a, b, c using
  non-deterministic inputs such that a + b + c = targetSum.
  It uses loop to perform iterative guessing and uses assertions to
  verify the condition.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "target_sum.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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
}

int main() {
    int targetSum;
    targetSum = __VERIFIER_nondet_int();
    assume_abort_if_not(targetSum >= 10 && targetSum <= 100);

    int a = 0, b = 0, c = 0;
    int iterations = 0;

    while (iterations < 100) {
        iterations++;
        int choice = __VERIFIER_nondet_int() % 3;

        switch (choice) {
        case 0:
            a++;
            break;
        case 1:
            b++;
            break;
        case 2:
            c++;
            break;
        default:
            break;
        }

        int currentSum = a + b + c;

        // Break the loop if we exactly reach the target sum
        if (currentSum == targetSum) {
            break;
        }
    }

    // Ensure that either we hit the target sum or exceeded iterations
    __VERIFIER_assert(a + b + c == targetSum || iterations == 100);

    return 0;
}