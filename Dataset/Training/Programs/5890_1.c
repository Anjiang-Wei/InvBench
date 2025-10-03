#include <stdio.h>
#include <stdlib.h>

// Define a verified error reach function
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_verifiable_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// A function to verify a simple property
void verify_property(int cond) {
    while (1) {
        if (cond) {
            break;
        }
        reach_error(); // should_abort on false condition
    }
}

// Function to compute sum of first n natural numbers that should satisfy a condition
int compute_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    __VERIFIER_assert(sum == (n * (n + 1)) / 2); // Ensuring sum matches the formula
    return sum;
}

// Function demonstrating a loop that updates a state
void state_machine_example(int num_iterations) {
    int state = 0;
    for (int k = 0; k < num_iterations; ++k) {
        if (k % 2 == 0) {
            state += k;
        } else {
            state -= k;
        }
    }
    verify_property(state >= -num_iterations);
}

// Main function
int main() {
    int n = 10; // This value may be determined using a nondeterministic approach
    int total_sum = compute_sum(n);
    printf("Sum of first %d natural numbers is: %d\n", n, total_sum);

    state_machine_example(n);

    return 0;
}