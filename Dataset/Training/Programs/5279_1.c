/*
Linear Congruential Generator
Generates a sequence of pseudo-random numbers.
The program demonstrates properties of LCG by verifying a characteristic relation.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "lcg.c", 5, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    unsigned int seed, a, c, m, iterations;
    unsigned int current, previous, count;

    // Initialize variables using nondeterministic inputs
    seed = __VERIFIER_nondet_uint();
    a = 1103515245; // Multiplier
    c = 12345;      // Increment
    m = 2147483648; // Modulus (2^31)
    iterations = __VERIFIER_nondet_uint();

    // Ensure valid conditions
    assume_abort_if_not(m > 0);
    assume_abort_if_not(iterations > 0);

    current = seed;
    count = 0;

    while (1) {
        // Record previous value
        previous = current;

        // LCG formula: X(n+1) = (a * X(n) + c) mod m
        current = (a * current + c) % m;

        // Verify a characteristic property of LCG
        __VERIFIER_assert(current != previous); // Ensure no immediate repetition

        if (!(count < iterations)) {
            break;
        }

        count = count + 1;
    }

    return 0;
}