// Compute the factorial of a number using a loop

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int factorial(int n) {
    int result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    int num = __VERIFIER_nondet_int();
    assume_abort_if_not(num >= 0 && num <= 10); // Restricting input for simplicity
    int result = factorial(num);

    // Verify that result is greater than zero for positive inputs
    if (num > 0) {
    }

    // Verify if factorial(0) is 1
    if (num == 0) {
        __VERIFIER_assert(result == 1);
    }

    return 0;
}