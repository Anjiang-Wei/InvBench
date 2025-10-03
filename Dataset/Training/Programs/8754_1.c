#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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
    int a, b;
    long long result, power;

    // Non-deterministically choose a and b
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Ensure a and b are within certain bounds
    assume_abort_if_not(a >= 1 && a <= 5);
    assume_abort_if_not(b >= 1 && b <= 5);

    result = 1;
    power = a;

    // Iterative process to calculate b-th power of a using simple multiplication
    // This loop essentially computes result = a^b
    for (int i = 1; i <= b; i++) {
        result *= a;
    }

    // Calculate power using a loop structure
    long long temp_result = a;
    for (int i = 1; i < b; i++) {
        temp_result *= a;
    }

    // Assert to verify that both methods give the same result
    __VERIFIER_assert(temp_result == result);

    printf("a: %d, b: %d, result: %lld\n", a, b, result);

    return 0;
}