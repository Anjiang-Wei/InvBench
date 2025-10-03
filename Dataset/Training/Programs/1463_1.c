/*
  Sum of Odd Numbers and Verification
  Compute the sum of the first odd numbers up to a limit
  and verify that n^2 is equal to the sum of the first n odd numbers
*/

extern void abort(void);
void reach_error() { abort(); }
extern void abort(void);
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int n, counter = 0;
    long long sum = 0;
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n <= 10);

    while (counter++ < n) {
        sum = sum + (2 * counter - 1); // adding the next odd number
    }

    __VERIFIER_assert(sum == (long long)n * n);

    return 0;
}