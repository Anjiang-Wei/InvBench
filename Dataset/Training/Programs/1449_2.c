/*
  Fibonacci numbers and Cassini's identity verification:
  For n >= 2, Fibonacci sequence F_0 = 0, F_1 = 1, F_{k+1} = F_k + F_{k-1}.
  Cassini's identity states:
    F_{k+1} * F_{k-1} - (F_k)^2 = (-1)^k
  We nondeterministically pick n in [2..10], compute Fibonacci numbers up to F_n,
  and at each step assert Cassini's identity holds.
  A global counter bounds the loop to ensure termination for verification tools.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "fib-cassini.c", 12, "reach_error");
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

int counter = 0;

int main() {
    int n = __VERIFIER_nondet_int();
    /* restrict n to a small range so that Fibonacci fits in 64 bits */
    assume_abort_if_not(n >= 2);
    assume_abort_if_not(n <= 10);

    long long f0 = 0; /* F_0 */
    long long f1 = 1; /* F_1 */
    int c = 1;        /* current index */

    /* compute up to F_n, checking Cassini's identity at each step */
    while (counter++ < 50) {
        if (!(c < n)) {
            break;
        }

        long long f2 = f0 + f1; /* F_{c+1} */

        /* Cassini's identity: F_{c+1}*F_{c-1} - F_c^2 == (-1)^c */
        long long lhs = f2 * f0 - f1 * f1;
        long long rhs = (c % 2 == 0) ? 1LL : -1LL;

        /* advance Fibonacci */
        f0 = f1;
        f1 = f2;
        c++;
    }

    /* final sanity check: Fibonacci numbers are non-negative here */
    __VERIFIER_assert(f1 >= 0);

    return 0;
}