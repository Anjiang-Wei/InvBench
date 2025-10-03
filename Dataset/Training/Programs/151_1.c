// New example program based on patterns and structures from given examples

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_example.c", 3, "reach_error"); }

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
    unsigned int a = 1;
    unsigned int b = 2;
    unsigned int c = 5;
    unsigned int sum = 0;

    while (a < 10) {
        sum += b;
        a++;
    }

    while (b < 10) {
        b += c;
        c--;
    }

    // Assert that the sum is not equal to a specific number to ensure verification
    __VERIFIER_assert(sum != 30);

    return 0;
}