// Program: Arithmetic routines with verification harness

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prog.c", 5, "reach_error"); }

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

/* Compute greatest common divisor using Euclid's algorithm */
int gcd(int a, int b) {
    assume_abort_if_not(a >= 0 && b >= 0);
    int steps = 0;
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
        steps++;
        /* prevent infinite loops */
        assume_abort_if_not(steps < 10000);
    }
    return a;
}

/* Compute least common multiple via gcd */
int lcm(int a, int b) {
    assume_abort_if_not(a >= 0 && b >= 0);
    if (a == 0 || b == 0) {
        return 0;
    }
    int g = gcd(a, b);
    long long res = (long long)a / g * b;
    /* ensure result fits in 32-bit signed int */
    assume_abort_if_not(res >= 0 && res <= 2147483647);
    return (int)res;
}

/* Compute sum of decimal digits */
int sumDigits(int x) {
    assume_abort_if_not(x >= 0);
    int sum = 0;
    while (x > 0) {
        int d = x % 10;
        sum += d;
        x = x / 10;
    }
    return sum;
}

/* Compute factorial of n (n <= 12) */
int factorial(int n) {
    assume_abort_if_not(n >= 0 && n <= 12);
    int res = 1;
    int i = 1;
    while (i <= n) {
        res = res * i;
        i++;
    }
    return res;
}

/* Check primality by trial division */
int isPrime(int n) {
    if (n < 2) {
        return 0;
    }
    int i = 2;
    while ((long long)i * i <= n) {
        if (n % i == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    /* nondeterministic inputs */
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && b >= 0 && a <= 1000000 && b <= 1000000);

    int origA = a;
    int origB = b;

    /* Compute gcd and verify non-negativity */
    int g = gcd(a, b);

    /* Compute lcm and verify relationship gcd * lcm == a * b */
    int l = lcm(a, b);
    long long prod1 = (long long)origA * origB;
    long long prod2 = (long long)g * l;

    /* Sum of digits of gcd */
    int sd = sumDigits(g);

    /* Reverse digits of gcd */
    int rev = 0;
    int temp = g;
    while (temp > 0) {
        int d = temp % 10;
        rev = rev * 10 + d;
        temp = temp / 10;
        __VERIFIER_assert(rev >= 0);
    }
    /* Sum of digits of reversed is equal to original sum */
    int sd_rev = sumDigits(rev);

    /* Factorial of (sum of digits) mod 13 */
    int n = sd % 13;
    int f = factorial(n);
    /* factorial should be non-negative */

    /* Check if original numbers are coprime */
    int coprime = (g == 1) ? 1 : 0;
    /* If coprime then lcm should equal product */
    if (coprime) {
    } else {
    }

    /* Primality test of sum of digits */
    int prime_sd = isPrime(sd);
    if (prime_sd) {
        /* For all i in [2, sqrt(sd)], sd % i != 0 */
        int i = 2;
        while ((long long)i * i <= sd) {
            i++;
        }
    } else {
        /* There exists a divisor in [2, sd] */
        if (sd >= 2) {
            int found = 0;
            int j = 2;
            while (j <= sd) {
                if (sd % j == 0) {
                    found = 1;
                }
                j++;
            }
        }
    }

    return 0;
}