// Simple Linear Congruential Generator (LCG) Example with Assertion
// This program generates pseudo-random numbers and checks properties of the LCG

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "lcg.c", 4, "reach_error"); }

extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int a = 1103515245;                  // Multiplier
    unsigned int c = 12345;                       // Increment
    unsigned int m = 0x80000000;                  // Modulus (2^31)
    unsigned int seed = __VERIFIER_nondet_uint(); // Non-deterministic seed

    assume_abort_if_not(seed < m);

    unsigned int current = seed;
    unsigned int counter = 0;
    unsigned int prev_value;

    while (counter++ < 10) {
        prev_value = current;
        current = (a * current + c) % m;

        // Ensure that the generated number is always less than modulus
        __VERIFIER_assert(current < m);

        // Additional check to see if the LCG is effectively changing the value
        assume_abort_if_not(current != prev_value);
    }

    return 0;
}