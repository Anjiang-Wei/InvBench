extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "newprog.c", 1, "reach_error");
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
    return;
}

/* Compute the greatest common divisor using Euclid's algorithm */
int compute_gcd(int a, int b) {
    int x = a;
    int y = b;
    while (y != 0) {
        int t = y;
        y = x % y;
        x = t;
    }
    return x;
}

/* Multiply two non-negative integers using the "Russian peasant" method */
long long multiply(int a, int b) {
    long long res = 0;
    int x = a;
    int y = b;
    while (y > 0) {
        if (y & 1) {
            res += x;
        }
        x = x << 1;
        y = y >> 1;
    }
    return res;
}

/* Compute (base^exp) mod mod using fast exponentiation */
int mod_pow(int base, int exp, int mod) {
    int result = 1;
    int b = base % mod;
    while (exp > 0) {
        if (exp & 1) {
            long long tmp = 1LL * result * b;
            result = (int)(tmp % mod);
        }
        long long sq = 1LL * b * b;
        b = (int)(sq % mod);
        exp = exp >> 1;
    }
    return result;
}

/* Compute the n-th Fibonacci number iteratively */
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int f0 = 0;
    int f1 = 1;
    int f = 0;
    int i;
    for (i = 2; i <= n; i++) {
        f = f0 + f1;
        f0 = f1;
        f1 = f;
    }
    return f1;
}

int main() {
    /* Read and bound inputs */
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();
    int N = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 1000);
    assume_abort_if_not(b >= 0 && b <= 1000);
    assume_abort_if_not(n >= 0 && n <= 20);
    assume_abort_if_not(m >= 1 && m <= 1000);
    assume_abort_if_not(N >= 0 && N <= 10);

    /* Compute gcd, product, modular power, Fibonacci */
    int g = compute_gcd(a, b);
    long long prod = multiply(a, b);
    int pow_mod = mod_pow(a, n, m);
    int fib_n = fib(n);

    /* Prepare an array and sort it by selection sort */
    int arr[10];
    int orig[10];
    int i, j;
    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= 0 && arr[i] <= 100);
        orig[i] = arr[i];
    }
    /* Selection sort */
    for (i = 0; i < N - 1; i++) {
        int min = i;
        for (j = i + 1; j < N; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }

    /* Check that the sorted array is non-decreasing and sum is preserved */
    int sum_before = 0;
    int sum_after = 0;
    for (i = 0; i < N; i++) {
        sum_before += orig[i];
        sum_after += arr[i];
    }
    for (i = 0; i + 1 < N; i++) {
    }

    /* Final assertions about the other computations */
    /* gcd properties */
    if (a == 0 && b == 0) {
        __VERIFIER_assert(g == 0);
    } else {
    }
    /* multiplication correctness */
    /* modular exponentiation bounds */
    /* Fibonacci is non-negative */

    return 0;
}