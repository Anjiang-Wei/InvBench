// A program that calculates the sum of even numbers within a given range
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "summing_even_numbers.c", 4, "reach_error"); }

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

int main() {
    int A = __VERIFIER_nondet_int();
    int B = __VERIFIER_nondet_int();
    assume_abort_if_not(A >= 0 && B >= A);

    long long sum = 0;
    for (int i = A; i <= B; i++) {
        if (i % 2 == 0) {
            sum += i;
        }
    }

    // Check if the calculated sum is indeed even
    __VERIFIER_assert(sum % 2 == 0);

    return 0;
}