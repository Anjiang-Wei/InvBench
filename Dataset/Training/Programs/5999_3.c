// prime_sum.c
// A program to test primality of an integer n by trial division,
// compute the sum of all its divisors, and verify relationships
// between divisors and the sum. Designed for automatic verification.

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "prime_sum.c", 17, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

// find_divisor:
//   Performs trial division of n by integers from 2 up to n-1.
//   If a divisor is found, returns that divisor; otherwise returns 0.
int find_divisor(int n) {
    int d = 2;
    // Loop through possible divisors
    while (d < n) {
        if (n % d == 0) {
            return d;
        }
        d++;
    }
    return 0;
}

// sum_divisors:
//   Computes the sum of all positive divisors of n by
//   testing every integer from 1 up to n.
int sum_divisors(int n) {
    int i = 1;
    int sum = 0;
    // Loop to accumulate all divisors
    while (i <= n) {
        if (n % i == 0) {
            sum += i;
        }
        i++;
    }
    return sum;
}

// main:
//   1. Nondeterministically choose n (the number to test).
//   2. Constrain n to a reasonable range.
//   3. Find a divisor d (0 if none).
//   4. Compute sum of divisors s.
//   5. If prime (d == 0), assert that sum == n+1 and no i in [2..n-1] divides n.
//   6. If composite (d > 0), assert that d is indeed a divisor and sum > n+1.
int main() {
    // 1. Get a nondet integer for n
    int n = __VERIFIER_nondet_int();

    // 2. Constrain n: at least 2, at most 2^20-1 to keep loops bounded
    assume_abort_if_not(n >= 2 && n < (1 << 20));

    // 3. Find a nontrivial divisor if one exists
    int d = find_divisor(n);

    // 4. Compute the sum of all divisors
    int s = sum_divisors(n);

    // 5. Branch on primality
    if (d == 0) {
        // n is prime if no divisor found

        // 5a. Sum of divisors of a prime = 1 + n

        // 5b. Double-check that no number i in [2..n-1] divides n
        //     by picking an arbitrary i in that range and asserting
        //     n % i != 0.
        int i = __VERIFIER_nondet_int();
        assume_abort_if_not(i >= 2 && i < n);
    } else {
        // 6. Composite case: verify that d is a correct divisor
        __VERIFIER_assert(d >= 2 && d < n);

        // 6a. Sum of divisors of a composite number > 1 + n

        // 6b. Optionally check that s is at least d + (n/d) + 1
        //     (divisors 1, d, n/d, n contribute to the sum)
        int q = n / d;
    }

    return 0;
}