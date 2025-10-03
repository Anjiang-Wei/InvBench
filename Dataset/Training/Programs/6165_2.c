// This program calculates the sum of even numbers in a sequence until a certain condition is met.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "even_sum.c", 7, "reach_error"); }
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
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 1000);

    int sum = 0;
    int i = 0;

    while (i < N) {
        if (i % 2 == 0) {
            sum += i;
        }
        i++;
    }

    // Verify the sum is not negative (should always be true)

    // Additionally, verify only even numbers were added
    __VERIFIER_assert(sum % 2 == 0);

    return 0;
}