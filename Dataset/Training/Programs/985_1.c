#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int calculate(int a, int b) {
    int result = 0;
    if (a > 10 && b < 5) {
        result = (a - b) * 2;
    } else if (a <= 10 && b >= 5) {
        result = (a + b) * 3;
    } else {
        result = a * b;
    }
    return result;
}

int main() {
    int x = 0, y = 0, z = 0;
    int input1, input2;

    // Simulate nondeterministic inputs
    input1 = rand() % 20; // Random number between 0 and 19
    input2 = rand() % 10; // Random number between 0 and 9

    // Main computation loop
    while (x < 100) {
        x++;
        y = calculate(input1, input2);
    }

    // Another loop to manipulate variables
    while (y > 0) {
        y -= 3;
        z += 2;
    }

    // Check a condition that can be verified
    __VERIFIER_assert((z - x) % 2 == 0);

    printf("x: %d, y: %d, z: %d\n", x, y, z);
    return 0;
}