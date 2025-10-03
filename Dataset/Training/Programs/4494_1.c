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
}

int main(void) {
    unsigned int a = 1;
    unsigned int b = 1;
    unsigned int fib = 0;
    unsigned int step = 0;

    // Loop to calculate Fibonacci numbers up to a certain number of steps
    while (step < 10) {
        fib = a + b;
        a = b;
        b = fib;
        step++;
    }

    // Verifying a property of the final computed Fibonacci number
    // In this case, we ensure that the Fibonacci number is even
    __VERIFIER_assert(fib % 2 == 0);

    return 0;
}