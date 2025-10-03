#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int complex_function(int a, int b) {
    int result = 0;
    if (a > b) {
        result = a - b;
    } else if (a < b) {
        result = b - a;
    } else {
        result = a;
    }
    return result;
}

int main() {
    int x = 100, y = 50, z = 0;
    int threshold = 200;

    // First loop to increment x and y based on a condition
    while (x < threshold) {
        if (x % 2 == 0) {
            x += 10;
        } else {
            y += 5;
        }
    }

    // Second loop to decrement x and y
    while (y > 0) {
        y -= 3;
        x -= 2;
    }

    // Use the complex_function
    z = complex_function(x, y);

    // Assertion to ensure the property holds
    __VERIFIER_assert(z >= 0 && z <= threshold);

    // Print the result
    printf("x: %d, y: %d, z: %d\n", x, y, z);

    return 0;
}