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

int main() {
    // Initialize variables
    unsigned int limit = 100000; // Define a limit for the loop
    unsigned int a = 0, b = 0, c = 0;

    // First loop that increments `a` and `b` with some computational logic
    while (a < limit) {
        if (a % 2 == 0) {
            b += 3; // Increment `b` by 3 if `a` is even
        } else {
            b++; // Increment `b` by 1 if `a` is odd
        }
        a++;
    }

    // Second loop to perform an operation with `b` and set `c`
    while (b > 0 && c < limit / 2) {
        c += 2;
        b -= 5; // Decrement `b` by 5 in each iteration
        if (b < 20) {
            b -= 2; // Adjust `b` decrement logic if it falls under 20
        }
    }

    // Verify conditions at the end to check correctness
    __VERIFIER_assert(c < limit);
    return 0;
}