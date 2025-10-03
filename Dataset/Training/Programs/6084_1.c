#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }
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

int main() {
    int z;
    long long a, b, sum;
    z = __VERIFIER_nondet_int();

    // Assume initial conditions
    assume_abort_if_not(z > 0);

    a = 1;
    b = 1;
    sum = 0;

    // Running a Fibonacci sequence sum
    while (sum < 1000 && z > 0) {
        sum += a;

        // Compute the next Fibonacci number
        long long temp = a;
        a = b;
        b = temp + b;

        z--; // Reducing z to control the loop run
    }

    __VERIFIER_assert(sum < 2000);
    printf("Sum = %lld\n", sum);
    return 0;
}