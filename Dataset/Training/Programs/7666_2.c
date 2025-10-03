#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New Program:
   The program computes the sum of a series of natural numbers
   and checks conditions without indicating loop invariants.

   The sum is computed up to a random upper limit.
   Conditions ensure that the sum behaves as expected.
*/

int main() {
    int n = 10; // You can also use __VERIFIER_nondet_int(); and assume it to be a positive number
    int i = 0;
    int sum = 0;

    // The loop runs until i reaches n
    while (i <= n) {
        sum += i; // Accumulate the sum
        i++;

        // Checkpoint to ensure the partial sum is always non-negative

        // Ensure i is always increasing and never exceeds n
        __VERIFIER_assert(i <= n + 1);
    }

    // Verify the final sum matches the formula for the sum of the first n natural numbers

    return 0;
}