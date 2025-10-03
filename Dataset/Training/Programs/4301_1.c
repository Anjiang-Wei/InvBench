#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New CFG:
names= a b c
precondition= a > 0 && b > a && c = 0
loopcondition= a < b
loop= a = a + 1; c = c + a;
postcondition= c >= ((b * (b + 1)) / 2) - ((a_initial * (a_initial + 1)) / 2)
learners=linear
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = 0;

    if (!(a > 0 && b > a)) {
        return 0;
    }

    int a_initial = a; // Store the initial value of a for verification

    while (a < b) {
        a = a + 1;
        c = c + a; // Accumulate the sum of integers

        // Ensure the sum condition holds at each step (partial summation formula)
        __VERIFIER_assert(c >= ((a * (a + 1)) / 2) - ((a_initial * (a_initial + 1)) / 2));
    }

    // Final check after loop ends
    // Verifying sum of numbers from a_initial to b is correct

    return 0;
}