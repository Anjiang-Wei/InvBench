extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprogram.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    int max_value, sum, x, count;

    max_value = __VERIFIER_nondet_int();
    assume_abort_if_not(max_value >= 1);

    sum = 0;
    count = 0;

    while (count < max_value) {
        x = __VERIFIER_nondet_int();

        // This condition controls the sum to not exceed a certain threshold
        if (x > 0 && sum + x < 100) {
            sum = sum + x;
        } else if (x < 0 && sum + x > 0) {
            sum = sum + x;
        }

        count++;
    }

    // Post-condition: The sum should be positive after the loop
    __VERIFIER_assert(sum >= 0);

    return 0;
}