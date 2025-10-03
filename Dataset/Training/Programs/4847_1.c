// C program to compute the sum of even Fibonacci numbers up to a limit

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibo_even_sum.c", 3, "reach_error"); }
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
    int limit, a, b, sum;

    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit >= 0 && limit <= 1000);

    a = 0;
    b = 1;
    sum = 0;

    while (1) {
        int next = a + b;

        if (!(next <= limit)) {
            break;
        }

        if (next % 2 == 0) {
            sum = sum + next;
        }

        a = b;
        b = next;
    }

    __VERIFIER_assert(sum % 2 == 0); // Ensure the sum is even

    return 0;
}