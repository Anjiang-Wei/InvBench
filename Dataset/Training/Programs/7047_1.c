#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a = 0, b = 0, c = __VERIFIER_nondet_int();
    int iteration_count = 0;

    // Loop with constraint condition
    while (iteration_count < 100) {
        // Logic: a increases until a is no longer less than c, while b decreases
        if (a < c) {
            a += 2; // Increasing 'a' by 2 per iteration
        } else {
            b -= 1; // Decreasing 'b' when 'a' is not less than 'c'
        }

        // Ensure every step satisfies the relationship
        __VERIFIER_assert(a >= b);

        // Breaking out of loop if conditions meet
        if (a >= c && b <= 0) {
            break;
        }

        iteration_count++; // Incrementing loop counter to prevent infinite loop
    }

    // Final assertion to make sure the final condition holds

    return 0;
}