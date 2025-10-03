#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
  Program to verify the sum of squares under non-deterministic constraints.
  The program evolves x and y dynamically while maintaining a summation property.
*/

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int limit = __VERIFIER_nondet_int();

    // Assume initial conditions
    if (!(x >= 0 && y >= 0 && limit > 0)) {
        return 0;
    }

    // Calculates the sum of squares continuously until the loop breaks
    long long sum_of_squares = 0;
    while (__VERIFIER_nondet_bool()) {
        if (x > y) {
            sum_of_squares += (long long)x * x;
            y++;
        } else {
            sum_of_squares += (long long)y * y;
            x++;
        }
        if (x + y > limit) {
            break;
        }
    }

    // Verify that we have a valid sum of squares in certain condition
    __VERIFIER_assert(sum_of_squares >= 0);

    return 0;
}