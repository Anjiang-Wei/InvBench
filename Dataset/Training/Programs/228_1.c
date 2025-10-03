#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

// Global variables and input values
int a = 0;
int b = 1;
int x = 0;
int y = 0;

// Function to simulate random input
int random_input() {
    return __VERIFIER_nondet_int() % 2; // Randomly returns 0 or 1
}

// Function to simulate some computation
void compute() {
    a = a + b;
    b = b + 2;
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

int main() {
    int i = 0;
    int input;

    // Main loop
    while (i < 10) {
        input = random_input();

        if (input == 1) {
            compute();
        } else {
            a = a - 1;
        }

        // Constraint condition
        if (a > 20) {
            x++;
        }

        if (b > 15) {
            y++;
        }

        i++;
    }

    // Verification condition
    __VERIFIER_assert(x <= 10 && y <= 5);

    return 0;
}