// Example program based on observed patterns

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
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
    unsigned int a = 1;
    unsigned int b = 20;
    unsigned int c = 0;

    // Loop with meaningful computations and conditions
    while (a < b) {
        if (a % 2 == 0) {
            c += a; // accumulate sum of even numbers
        } else {
            c -= (a + 1); // subtract next number after an odd number
        }
        a++;
    }

    // The condition to verify
    __VERIFIER_assert(c != 0);

    return 0;
}