// New Example Program

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 4, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 1); // Ensure n is greater than 1 for meaningful computation

    // Initializing variables
    int i = 0, sum = 0, product = 1;

    // Loop for computation
    while (i < n) {
        if (i % 2 == 0) {
            sum += i; // Sum of even indices
        } else {
            product *= i; // Product of odd indices
        }
    }

    // Final assertions to ensure correctness of conditions
    __VERIFIER_assert(sum >= 0);     // Sum should be non-negative
    __VERIFIER_assert(product >= 1); // Product should remain positive

    return 0;
}