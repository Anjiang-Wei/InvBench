extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    unsigned int a = 1;
    unsigned int b = 10;
    unsigned int c = 0;

    while (a < b) {
        a += 1;
        c += a * a; // summing squares of 'a' until 'a' reaches 'b'
    }

    // Verify that the result `c` is less than an upper bound
    __VERIFIER_assert(c < 500);

    return 0;
}