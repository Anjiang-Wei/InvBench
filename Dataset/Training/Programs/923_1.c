/*
    Counting Positive and Negative Numbers
    This program reads a sequence of numbers and counts how many are
    positive and how many are negative. It stops when zero is entered.

    The program demonstrates typical loop usage and condition checking,
    suitable for automated analysis and verification.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "countposneg.c", 10, "reach_error"); }
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
    int num;
    int positive_count = 0;
    int negative_count = 0;

    while (1) {
        // Obtain a nondeterministic integer
        num = __VERIFIER_nondet_int();

        // Stop input when zero is encountered
        if (num == 0) {
            break;
        }

        // Update counts based on the value of the number
        if (num > 0) {
            positive_count++;
        } else if (num < 0) {
            negative_count++;
        }
    }

    // Assertions for final results
    __VERIFIER_assert(positive_count >= 0);

    return 0;
}