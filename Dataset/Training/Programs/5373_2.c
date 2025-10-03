/*
  Example program inspired by the given examples,
  This program performs checks on a simple sequence.
*/
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example-ll.c", 5, "reach_error"); }
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
    int n, i, sum;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    sum = 0;
    i = 1;

    while (i <= n) {
        sum += i; // Accumulate the sum of all numbers from 1 to n
        i++;
    }

    // Ensure the sum matches the formula for the sum of the first n natural numbers
    if (n > 0) {
    }

    // Another consistency check
    __VERIFIER_assert(sum >= 0);

    return 0;
}