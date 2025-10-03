#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Error reached\n");
    exit(1);
}
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Define a range for valid input
#define MIN_INPUT 1
#define MAX_INPUT 10

// Configuration variables
int a = 0, b = 0, c = 0, d = 0;

// Function to represent some computational logic
void update_variables(int input) {
    if (input % 2 == 0) {
        a += input;
        b -= input;
    } else {
        c += input * 2;
        d -= input / 2;
    }
    if (a > 20) {
        a = 20;
    }
    if (b < -20) {
        b = -20;
    }
    if (c > 40) {
        c = 40;
    }
    if (d < -10) {
        d = -10;
    }
}

int main() {
    int loop_counter = 0;
    int limit = 20;

    while (loop_counter < limit) {
        int input = __VERIFIER_nondet_int();

        // Assume the input is within a valid range
        if (input < MIN_INPUT || input > MAX_INPUT) {
            continue;
        }

        update_variables(input);

        // Check some conditions
        __VERIFIER_assert(c >= 0 && c <= 40);

        loop_counter++;
    }

    return 0;
}