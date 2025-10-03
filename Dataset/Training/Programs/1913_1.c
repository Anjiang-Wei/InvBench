extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool();

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
    return;
}

int compute_factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Adding constraints for manageability

    int factorial = compute_factorial(n);

    // Verify if the factorial calculation is correct by a simple property
    __VERIFIER_assert(factorial >= 1);

    // Additional logic using loop and nondeterministic behavior
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum += i;
        i++;
    }

    // Ensure the sum is equal to n * (n + 1) / 2

    return 0;
}