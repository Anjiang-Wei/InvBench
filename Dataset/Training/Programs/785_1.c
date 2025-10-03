#include <stdio.h>
#include <stdlib.h>

// Function declarations and error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error(const char *msg) { __assert_fail("0", msg, __LINE__, "reach_error"); }

void __VERIFIER_assert(int cond, const char *msg) {
    if (!cond) {
        reach_error(msg);
        abort();
    }
    return;
}

// A recursive function to compute factorial using pointers
int compute_factorial(int *n) {
    if (*n <= 1) {
        return 1;
    } else {
        int temp = *n - 1;
        return (*n) * compute_factorial(&temp);
    }
}

// Another function that calculates something based on inputs
int some_computation(int a, int b) {
    int result = 0;
    for (int i = 0; i < a; i++) {
        result += (b + i);
    }
    return result;
}

// A simple loop to verify some conditions
int verify_conditions(int x, int y) {
    int z = 0;
    while (x < 10 && y > 0) {
        z += x * y;
        x++;
        y--;
    }
    return z;
}

int main(void) {
    int n = 5;
    int factorial = compute_factorial(&n);
    printf("Factorial of %d is %d.\n", n, factorial);

    // Verify the computation
    __VERIFIER_assert(factorial == 120, "Factorial is incorrect");

    int a = 3, b = 4;
    int computation_result = some_computation(a, b);
    printf("Result of some computation with a=%d, b=%d is %d.\n", a, b, computation_result);

    // Verify the computation result

    int x = 2, y = 5;
    int verified_result = verify_conditions(x, y);
    printf("Verified result of conditions with x=%d, y=%d is %d.\n", x, y, verified_result);

    // Verify the condition result

    return 0;
}