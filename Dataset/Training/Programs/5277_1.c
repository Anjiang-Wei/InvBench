extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int();
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned int sum = 0;

    // Increment x up to a random upper limit while doubling y
    while (x < 10) {
        int decision = __VERIFIER_nondet_int();
        if (decision) {
            x++;
            y += 2;
        } else {
            break;
        }
    }

    // Calculate the sum of x and y
    sum = x + y;

    // Verifying the computation
    __VERIFIER_assert(sum >= x && sum >= y);

    return 0;
}