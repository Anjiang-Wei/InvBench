#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "mystery_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int counter = 0;

int main() {
    int a, b, c;
    long long product, sum;

    // Receive nondeterministic integers
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume initial constraints
    assume_abort_if_not(a >= 1 && b >= 1);

    product = 1;
    sum = 0;
    c = 1;

    // Main loop simulating some complex mathematical series or calculation
    while (counter++ < 100) {

        if (!(c <= a * b)) {
            break;
        }

        product = product * c; // Computing a factorial kind of product
        sum += product / c;    // Accumulating to a series sum

        c++;
    }

    // Final state condition to check
    __VERIFIER_assert((product >= 1) && (sum >= 0));

    printf("Computation completed. Resulting sum: %lld\n", sum);
    return 0;
}