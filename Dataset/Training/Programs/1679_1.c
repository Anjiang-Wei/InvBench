/* Counting the number of bits set to 1 (Hamming weight) in an integer */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "count_bits.c", 5, "reach_error"); }
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
    int n, count;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 255); // limit n for simplicity

    count = 0;

    while (1) {
        if (n == 0) {
            break;
        }

        if (n % 2 == 1) {
            count = count + 1;
        }
        n = n / 2;
    }

    __VERIFIER_assert(count >= 0 && count <= 8); // In this range because n is between 0 and 255

    return 0;
}