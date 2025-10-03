#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n = __VERIFIER_nondet_int(); // Non-deterministic input N
    if (n <= 0) {
        return 0; // Assumption: N must be positive
    }

    int i = 0;          // Loop variable
    int sum = 0;        // Sum of the first N even numbers
    int even_count = 0; // Count of even numbers encountered

    // Loop to compute the sum of the first N even numbers
    while (i < n) {
        int x = __VERIFIER_nondet_int(); // Non-deterministic next number

        if (x % 2 == 0) { // Check if even
            sum += x;     // Add to sum if even
            even_count++; // Increment count
            i++;          // Move to the next number
        }
    }

    // Check if the even count matches N
    __VERIFIER_assert(even_count == n);

    // Output the result
    printf("The sum of the first %d even numbers is: %d\n", n, sum);

    return 0;
}