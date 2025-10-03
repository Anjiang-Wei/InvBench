/*
 * A program to calculate and verify the sum of powers of 2 up to a given limit.
 * It takes a non-deterministic positive integer N and calculates the sum:
 * S = 2^0 + 2^1 + 2^2 + ... + 2^(N-1).
 * After the computation, it verifies that the total sum S minus the last power of two equals the remaining sum.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "power_sum.c", 11, "reach_error"); }
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

int main() {
    int N = __VERIFIER_nondet_int();

    // Assume N is positive and not very large
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N <= 30);

    int power = 1; // 2^0
    int sum = 0;
    int i;

    for (i = 0; i < N; i++) {
        sum += power; // Add the current power of 2 to the sum
        power *= 2;   // Calculate the next power of 2
    }

    // The sum of powers of 2 up to 2^(N-1) is 2^N - 1
    int expected_sum = power - 1;

    // Verify that the sum calculated matches the closed-form result
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}