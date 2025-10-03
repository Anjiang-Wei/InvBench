// This program checks if an arbitrary sequence of numbers has an even sum

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "even_sum.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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
    int sum = 0;
    int n = 0;

    // Simulating a sequence of numbers
    // Constraint: Ensure n stays within a reasonable bound
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    while (n > 0) {
        int num = __VERIFIER_nondet_int();
        assume_abort_if_not(num >= 0);

        if (num % 2 == 0) {
            sum += num;
        }

        n--;
    }

    // Verify that the sum of even numbers is even
    __VERIFIER_assert(sum % 2 == 0);

    return 0;
}