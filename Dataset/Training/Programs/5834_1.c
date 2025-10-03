/*
  Verify the identity:
    sum_{i=1..N} i^3 == (sum_{i=1..N} i)^2

  The program computes the sum of the first N natural numbers
  and the sum of their cubes in a loop, then checks the well‐known
  mathematical identity sumCube == sum^2.

  This is intended for automated verification tools.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_cubes.c", 10, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    /* only nonnegative N, small enough to avoid overflow in sumCube */
    if (N < 0) {
        return 0;
    }
    assume_abort_if_not(N <= 10000);

    long long sum = 0;
    long long sumCube = 0;
    int i = 1;

    /* loop computing both sums */
    while (i <= N) {
        sum += i;
        sumCube += (long long)i * i * i;
        i++;
    }

    /* final check of the identity */
    __VERIFIER_assert(sumCube == sum * sum);

    return 0;
}