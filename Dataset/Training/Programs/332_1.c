#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int complex_logic(int x, int y, int z) {
    if (x > 0 && y > z) {
        return x + y - z;
    } else if (x < 0 && z > y) {
        return x - y + z;
    } else {
        return x * y * z;
    }
}

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0; // Used in loop
    int result = 0;

    // Simulate complex algorithm with nested loops and conditions
    for (a = 0; a < 5; a++) {
        for (b = 0; b < 5; b++) {
            for (c = 0; c < 5; c++) {
                d = __VERIFIER_nondet_int(); // Non-deterministic input
                if (d >= 0 && d < 5) {
                    result = complex_logic(a, b, c);
                    __VERIFIER_assert(result >= 0);
                }
            }
        }
    }

    // Additional condition to demonstrate verification
    int e = __VERIFIER_nondet_int();
    if (e > 0 && e < 100) {
    }

    printf("Final result: %d\n", result);
    return 0;
}