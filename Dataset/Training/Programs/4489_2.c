#include <stdio.h>
#include <stdlib.h>

// Function to simulate an error reaching condition
void reach_error() {
    printf("Error reached.\n");
    exit(1);
}

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Global state variable
int status = 0;

// Function to simulate some state changes
void update_status(int value) {
    if (value % 2 == 0) {
        status += value;
    } else {
        status -= value;
    }
}

// Main function with loops and constraints
int main(void) {
    int n = __VERIFIER_nondet_int();
    int x = 0, y = 0;

    if (n <= 0) {
        return 0;
    }

    while (x < n) {
        x++;
        y += 2;
        update_status(y);
    }

    __VERIFIER_assert(y == 2 * n);

    return 0;
}