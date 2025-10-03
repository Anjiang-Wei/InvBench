#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a = 1, b = 1, c = 0;
    int sum = 0;

    // Assume we want to compute the sum of a sequence without exceeding a bound
    int max_iterations = 100;
    int counter = 0;

    while (counter < max_iterations) {
        __VERIFIER_assert(a > 0 && b > 0); // To ensure a and b remain positive

        a = a + 2;
        b = b * 2;
        c = c + a + b;

        sum += c;

        // Constraint to ensure sum doesn't grow unbounded
        if (sum > 10000) {
            printf("Reached sum limit, exiting loop.\n");
            break;
        }

        counter++;
    }

    // Final assertion to ensure loop executed an expected number of times

    printf("Final Values: a = %d, b = %d, c = %d, sum = %d\n", a, b, c, sum);
    return 0;
}