// Verification-focused C Program Example

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verify_program.c", 3, "reach_error"); }
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
    return;
}

// Custom function to calculate factorial for verification purposes
long factorial(int n) {
    long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    long fact_result;

    num = __VERIFIER_nondet_int();

    // Assuming num is within a realistic range for factorial computation to avoid overflow
    assume_abort_if_not(num >= 0 && num <= 15);

    fact_result = factorial(num);

    // Checking that the factorial result is positive for non-negative inputs

    // Moreover, ensure specific known facts
    __VERIFIER_assert(fact_result == 1 || num > 0);

    return 0;
}