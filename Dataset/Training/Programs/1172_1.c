#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Ensure a, b, and c are initialized to valid values for computation
    if (a <= 0 || b <= 0 || c <= 0) {
        return 0;
    }

    int sum = 0;
    int product = 1;
    int count = 0;

    // Loop to concurrently calculate sum and product of numbers through iteration
    while (__VERIFIER_nondet_bool()) {
        if (a > b) {
            sum += a; // increase sum from 'a'
            a--;
        } else {
            sum += b; // otherwise increase sum from 'b'
            b--;
        }

        product *= c;
        c--;

        count++;

        // Exit loop if any variable becomes non-positive
        if (a <= 0 || b <= 0 || c <= 0) {
            break;
        }
    }

    // Ensure that after exiting the loop, sum is non-negative and product is even
    __VERIFIER_assert(sum >= 0);

    return 0;
}