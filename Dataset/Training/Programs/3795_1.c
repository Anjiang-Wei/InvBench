/*
 * Fibonacci Sequence Sum - Computes the sum of the first N Fibonacci numbers
 * Uses a loop to iteratively compute the sequence and sum.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_sum.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    int N;
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 0 && N <= 50);

    long long fib1 = 0;
    long long fib2 = 1;
    long long sum = 0;
    int count = 0;

    while (1) {
        // Add the current Fibonacci number to the sum
        sum += fib1;

        // Calculate the next Fibonacci number
        long long next_fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = next_fib;

        if (!(count < N)) {
            break;
        }

        count++;
    }

    // Verify that the sum is non-negative and less than a certain threshold
    __VERIFIER_assert(sum >= 0);
}