#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int calculate_fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return calculate_fibonacci(n - 1) + calculate_fibonacci(n - 2);
}

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    n = 10; // For example purposes, use a fixed value. Replace with external input for testing.
    int fib_sequence[n];

    for (int i = 0; i < n; i++) {
        fib_sequence[i] = calculate_fibonacci(i);
    }

    int prime_count = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(fib_sequence[i])) {
            prime_count++;
        }
    }

    // Let's make a meaningful assertion: The number of primes in the
    // first `n` Fibonacci numbers should be less than `n`.
    __VERIFIER_assert(prime_count < n);

    printf("Fibonacci sequence of first %d numbers are: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib_sequence[i]);
    }
    printf("\nNumber of primes in Fibonacci sequence: %d\n", prime_count);

    return 0;
}