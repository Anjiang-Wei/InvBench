extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "difference.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

// Calculate the difference until a condition is met
int main() {
    int target = 100; // Target value
    int sum = 0;
    int step = 1;
    int iterations = __VERIFIER_nondet_int();

    // Assume that the number of iterations is within reasonable bounds
    assume_abort_if_not(iterations >= 1 && iterations <= 50);

    // Iterate to calculate the difference
    for (int i = 0; i < iterations; i++) {
        sum += step;
        step += 2; // Increment step by an odd number pattern
        if (sum >= target) {
            break; // Exit loop if the cumulative sum exceeds or equals the target
        }
    }

    // Verify that the sum does not exceed an unrealistic bound
    __VERIFIER_assert(sum <= 5000);

    return 0;
}