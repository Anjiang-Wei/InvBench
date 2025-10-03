#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "new_program.c", 5, "reach_error");
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// A function that performs some complex calculations
int complex_calculation(int x, int y) {
    int result = x;
    for (int i = 0; i < y; i++) {
        result = (result * x + y) % 10007;
    }
    return result;
}

// A function that checks certain properties
void check_properties(int a, int b, int c) {
    __VERIFIER_assert(a + b + c > 0);
}

// The main function contains logic that can be verified
int main() {
    int input1 = __VERIFIER_nondet_int();
    int input2 = __VERIFIER_nondet_int();
    int input3 = __VERIFIER_nondet_int();

    assume_abort_if_not(input1 > 0 && input1 < 1000);
    assume_abort_if_not(input2 > 0 && input2 < 1000);
    assume_abort_if_not(input3 > 0 && input3 < 1000);

    // Initialize variables
    int result = 0;
    int counter = 0;
    int threshold = 5000;

    // Start a loop that performs calculations and checks properties
    while (counter < 10) {
        int temp = complex_calculation(input1, input2);
        check_properties(input1, input2, input3);

        // Update the result based on some condition
        if (temp < threshold) {
            result += temp;
        } else {
            result -= temp;
        }

        // Update inputs and counter
        input1 = (input1 * 2) % 1000;
        input2 = (input2 * 3) % 1000;
        input3 = (input3 * 4) % 1000;
        counter++;
    }

    // Check final properties of the result

    // Print the result
    printf("Final result: %d\n", result);

    return 0;
}