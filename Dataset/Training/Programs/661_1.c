#include <stdio.h>

// Function declarations for potential external verification use.
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Simulating a reach_error function using standard assert_fail function.
void reach_error() { __assert_fail("0", "custom_verify.c", 5, "reach_error"); }

// A function to simulate an external non-deterministic integer generator.
int __VERIFIER_nondet_int(void) {
    int num;
    printf("Enter a non-deterministic number (int): ");
    scanf("%d", &num);
    return num;
}

// A function to simulate an external non-deterministic boolean generator.
_Bool __VERIFIER_nondet_bool() {
    int choice;
    printf("Enter a non-deterministic boolean (0 or 1): ");
    scanf("%d", &choice);
    return choice ? 1 : 0;
}

// A simplified assert function to simulate verification conditions.
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Summation function to be invoked conditionally.
void conditional_increment(int *value) {
    *value += 10; // Arbitrarily chosen increment
}

int main() {
    int total_sum = 0;
    int limit;

    limit = __VERIFIER_nondet_int(); // Set a nondeterministic limit
    if (limit < 0) {
        printf("Limit should be non-negative. Terminating.\n");
        return -1;
    }

    int counter = 0;

    // Loop with constraints and conditional operations
    while (counter < limit) {
        _Bool decision = __VERIFIER_nondet_bool(); // Non-deterministic branching
        if (decision) {
            conditional_increment(&total_sum);
        }

        __VERIFIER_assert(total_sum >= 0); // Ensuring total_sum should never become negative
        counter++;
    }

    printf("Total sum: %d\n", total_sum);
    printf("Counter reached the limit: %d\n", counter == limit);

    // Verification to ensure the invariant holds at the end

    return 0;
}