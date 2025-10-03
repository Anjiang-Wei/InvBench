#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 10, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int calculate_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1 = 48; // You can replace these with some nondeterministic inputs
    int num2 = 18; // for verification purposes
    int gcd = calculate_gcd(num1, num2);

    // Known GCD of 48 and 18 is 6

    // Fibonacci-like loop with verification
    int fib_limit = 10;
    int fib_a = 0, fib_b = 1;
    int fib_nth = 0;

    for (int i = 3; i <= fib_limit; ++i) {
        fib_nth = fib_a + fib_b;
        fib_a = fib_b;
        fib_b = fib_nth;
    }

    // Assert the 10th Fibonacci number is 34 (0-based index)
    // Fib sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34
    __VERIFIER_assert(fib_nth == 34);

    printf("GCD is %d\n", gcd);
    printf("10th Fibonacci number is %d\n", fib_nth);

    return 0;
}