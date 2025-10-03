#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Example explanation:
The program initializes two pointers moving towards each other in a simulated list.
The goal is to meet at the center. The program should ensure that data processed before the
meeting point matches the combined precondition and postcondition requirement.
Precondition: start < end && start % 2 == 0 && end % 2 == 0
Postcondition: start == end + 1 (they meet eventually after processing all elements)
*/

int main() {
    int start = __VERIFIER_nondet_int();
    int end = __VERIFIER_nondet_int();

    // Precondition check
    if (!(start < end && start % 2 == 0 && end % 2 == 0)) {
        return 0;
    }

    int sum = 0;

    // Loop invariant: Start <= end + 1, ensuring progress
    while (start <= end) {
        // Process current elements
        sum += start;
        sum += end;

        // Move towards center
        start++;
        end--;

        // Maintain that sum is always even
        __VERIFIER_assert(sum % 2 == 0);
    }

    // Postcondition

    return 0;
}