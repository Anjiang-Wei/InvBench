#include <stdio.h>
#include <stdlib.h>

// Declare external functions often used in verification tools
extern void abort(void);
extern void __VERIFIER_error() __attribute__((__noreturn__));
void reach_error() { __VERIFIER_error(); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to simulate assertion
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        reach_error();
    }
}

int main() {
    int length = __VERIFIER_nondet_int(); // Input length
    int width = __VERIFIER_nondet_int();  // Input width
    int area, perimeter;

    // Assume conditions to restrict input values
    assume_abort_if_not(length >= 1 && length <= 100);
    assume_abort_if_not(width >= 1 && width <= 100);

    area = 0;
    perimeter = 0;

    // Loop to calculate the area of a rectangle
    int i = 0;
    while (i < length) {
        area += width;
        i++;
    }

    // Loop to calculate the perimeter of a rectangle
    int j = 0;
    while (j < 2) {
        perimeter += (2 * length) + (2 * width);
        j++;
    }

    // Verify the correctness of the area and perimeter calculations
    __VERIFIER_assert(area == length * width);

    return 0;
}