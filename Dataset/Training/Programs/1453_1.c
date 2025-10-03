#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Custom logic:
   The program assigns two initial nondet values to two variables, a and b.
   It will enter a loop where both variables are manipulated with distinct logic.
   The loop continues until a certain relationship holds true between a and b.
   After the loop, the program verifies a final condition using an assertion.
   This logic models a controlled counting and comparison scenario.
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Initial condition to ensure some relationship before entering the loop
    if (!(a < b)) {
        return 0;
    }

    // A loop conditional that modifies 'a' and 'b' using distinct patterns
    while (a < b) {
        if (a % 2 == 0) {
            a += 5; // Increment a based on its parity
        } else {
            a += 3; // Smaller increment if a is odd
        }

        if (b % 3 == 0) {
            b -= 4; // Decrement b based on a multiple of 3 condition
        } else {
            b -= 2; // Smaller decrement otherwise
        }
    }

    // After the loop, the program checks for a deterministic relationship between the variables
    __VERIFIER_assert((a - b) >= 0 && (a - b) < 10);

    // Output the result for manual inspection, if ever needed
    printf("a: %d, b: %d\n", a, b);

    return 0;
}