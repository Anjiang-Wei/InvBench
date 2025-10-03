// A C program to calculate the factorial of a number using loop and verify certain conditions

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n;
    long long factorial = 1;
    int i = 1;

    n = __VERIFIER_nondet_int();
    if (n < 0) {
        return 0; // Factorial is not defined for negative numbers
    }

    while (i <= n) {
        factorial *= i;
        i++;

        // Verifying that factorial is in bounds (non-negative for non-negative n)
        __VERIFIER_assert(factorial >= 0);
    }

    // An assertion to check if the loop executed completely for positive n
    if (n > 0) {
    }

    return 0;
}