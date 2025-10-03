#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_verification.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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

int counter = 0;
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 1000); // Ensures n is a positive number and bound for computational feasibility

    int a = 0, b = 1, c; // Initialize the first two Fibonacci numbers and a placeholder for the next number in series

    while (counter++ < 1000) { // Fine-tuning the loop to prevent infinite execution
        c = a + b;             // Calculate the next Fibonacci number
        // Ensures the condition after each computation is intact
        __VERIFIER_assert(a >= 0 && b >= 0 && c > a); // Fibonacci numbers are positive and increasing

        if (!(c < n)) {
            break; // Exit the loop if next number exceeds n
        }

        a = b; // Shift the sequence for next iteration
        b = c;
    }
}