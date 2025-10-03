extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    unsigned int a = 1;
    unsigned int b = 0;
    unsigned int n = 10; // number of loop iterations

    // Compute factorial of n
    while (a <= n) {
        if (a >= 5) {
            // Increment if we reach the halfway point
            b = b + 1;
        }
        a++;
    }

    // The value of 'b' should be 6 since we increment 6 times from a=5 to a=10 (inclusive)
    __VERIFIER_assert(b == 6);

    return 0;
}