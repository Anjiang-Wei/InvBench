// A C program designed to be analyzed and verified by automated verification tools

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

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
    unsigned int a = 0;
    unsigned int b = 50;
    unsigned int sum = 0;

    // Loop incrementing a and summing up its values
    while (a < b) {
        sum += a;
        a += 3;
    }

    // Verify the sum is equal to the expected result
    __VERIFIER_assert(sum == 408);

    return 0;
}