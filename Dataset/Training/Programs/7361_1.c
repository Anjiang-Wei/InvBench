#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "ExampleProgram.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(c > 0);

    // Simple loop with arithmetic progression
    int sum = 0;
    for (int i = 1; i <= 100; i++) {
        sum += i * a;
    }

    // Function with conditional assertions
    int result = sum + b * c;
    if (result < sum) {
        __VERIFIER_assert(result >= sum);
    }

    // Nested loop with a more complex condition
    int count = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i * j > 20 && i < j) {
                count++;
            }
        }
    }

    // Implement a simple state machine logic
    int state = 0;
    int input = __VERIFIER_nondet_int();
    assume_abort_if_not(input >= 0 && input <= 5);

    switch (input) {
    case 0:
        state = 1;
        break;
    case 1:
        state = 2;
        break;
    case 2:
        if (state == 2) {
            state = 3;
        }
        break;
    case 3:
        if (state == 3) {
            state = 4;
        }
        break;
    case 4:
        if (state == 4) {
            state = 0;
        }
        break;
    case 5:
        state = 5;
        break;
    default:
        state = -1;
    }

    // Final assertion to verify an invariant

    printf("Final state: %d\n", state);
    printf("Final result: %d\n", result);
    printf("Count of conditions met in nested loop: %d\n", count);

    return 0;
}