#include <limits.h>

/*
Fibonacci Sequence Calculation
Performs a calculation to verify the property of Fibonacci numbers:
f(n-1) * f(n+1) - f(n)^2 == (-1)^n
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
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
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2 && n <= 46); // To avoid integer overflow

    int f0 = 0, f1 = 1; // Base case: Fibonacci sequence starts here
    int prev = f0, curr = f1;
    int temp, counter = 2;

    // Calculate Fibonacci sequence up to f(n) and f(n+1)
    while (counter <= n) {
        temp = curr;
        curr = curr + prev;
        prev = temp;
        counter++;
    }

    int fn = curr;                   // f(n)
    int fn_minus_1 = prev;           // f(n-1)
    int fn_plus_1 = fn + fn_minus_1; // f(n+1)

    // Verify the property: f(n-1) * f(n+1) - f(n)^2 == (-1)^n
    int lhs = fn_minus_1 * fn_plus_1 - fn * fn;
    int rhs = (n % 2 == 0) ? 1 : -1;

    __VERIFIER_assert(lhs == rhs);

    return 0;
}