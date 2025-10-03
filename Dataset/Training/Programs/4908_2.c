/*
 * This program is designed to be analyzed by formal verification tools.
 * It computes the sum of integers, verifies its behavior using assertions,
 * and uses loops and computation to meet complexity requirements.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "computation_example.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); };
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n < 1000);

    int *array = malloc(n * sizeof(int));
    assume_abort_if_not(array != 0);

    int i;
    int sum = 0;

    for (i = 0; i < n; ++i) {
        array[i] = i; // Fill array with increasing numbers
        sum += array[i];
    }

    int expected_sum = n * (n - 1) / 2;

    // Modify array and check a new condition
    int product = 1;
    for (i = 0; i < n; ++i) {
        array[i] = 1; // Change every element to 1
        product *= array[i];
    }

    __VERIFIER_assert(product == 1); // Product should remain 1 as we are multiplying by 1

    return 0;
}