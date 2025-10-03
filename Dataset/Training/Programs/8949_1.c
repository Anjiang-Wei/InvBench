/*
  This program calculates the sum of squares of an array of non-negative integers.
  It uses dynamic memory allocation and checks a condition on the calculated sum.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_squares.c", 8, "reach_error"); }
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
void *malloc(unsigned int size);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N <= 1000);

    int i;
    int *array = malloc(N * sizeof(int));
    assume_abort_if_not(array != 0);

    // Fill the array with non-negative integers
    for (i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0);
    }

    long long sum_of_squares = 0;

    for (i = 0; i < N; i++) {
        sum_of_squares += (long long)array[i] * array[i];
    }

    // Check that the sum of squares is always non-negative
    __VERIFIER_assert(sum_of_squares >= 0);

    // Assuming some arbitrary condition for demonstration purposes

    return 0;
}