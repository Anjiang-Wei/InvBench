/*
Fibonacci-like Sequence Verification
Computes a sequence similar to Fibonacci numbers,
ensures that the nth term is greater than or equal to the n-1 term but less than
or equal to twice the n-1 term plus twice the n-2 term.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fiblike.c", 9, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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

int counter = 0;
int main() {
    unsigned int n;
    long long current, prev1, prev2;
    n = __VERIFIER_nondet_uint();

    // Initialize the sequence
    prev2 = 0;
    prev1 = 1;
    current = 1;

    // Generate the sequence
    while (counter++ < 100) {
        __VERIFIER_assert(current <= 2 * prev1 + 2 * prev2);

        if (!(n > 0)) {
            break;
        }

        n = n - 1;

        // Update sequence terms
        long long new_value = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
        current = new_value;
    }

    return 0;
}