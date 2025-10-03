// New C Program

#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

void accumulate_and_check_fibonacci_sequence(int N) {
    assume_abort_if_not(N > 0);

    unsigned long long sum = 0;
    int i = 0, value;

    while (i < N) {
        value = fib(i);
        sum += value;

        // Check a condition involving the sum
        if (i % 2 == 0) {
            assume_abort_if_not(sum % 2 == 0);
        }

        i++;
    }

    __VERIFIER_assert(sum >= fib(N - 1)); // At the end, the sum should be at least the last Fibonacci number
}

int main() {
    int limit = __VERIFIER_nondet_int();
    accumulate_and_check_fibonacci_sequence(limit);
    return 0;
}