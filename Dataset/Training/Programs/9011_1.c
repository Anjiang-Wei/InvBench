#include <stdio.h>

// Function prototypes for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "example_program.c", 8, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

// Custom assert function for verification
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort(); // Halts the program after a failed assertion
    }
}

// Main function with computational logic and loop
int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int threshold = __VERIFIER_nondet_int();

    // The precondition ensures meaningful starting values
    if (a < 0 || b <= 0 || threshold > 100) {
        return 0; // Skip computations if initial conditions do not match
    }

    int sum = 0;
    int steps = 0;

    // Loop that accumulates the sum of all multiples of 'b' less than 'threshold'
    while (sum < threshold) {
        sum += b;
        steps++;

        // If the sum exceeds a specified value or steps are too many, stop
        if (sum > 2 * threshold || steps > 1000) {
            break;
        }
    }

    // Postcondition to check if the computation is consistent
    __VERIFIER_assert(sum >= 0 && steps < 1000);

    // Output results
    printf("Final sum is %d achieved in %d steps.\n", sum, steps);
    return 0;
}