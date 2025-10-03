/* Fibonacci Sequence and Sum Verification */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-ll.c", 4, "reach_error"); }
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

int counter = 0;
int main() {
    int n;
    long long fib_prev, fib_curr, temp;
    long long sum, expected_sum;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    fib_prev = 0;
    fib_curr = 1;
    sum = 0;
    expected_sum = 1;

    while (counter++ < 100) {
        __VERIFIER_assert(sum == fib_prev + fib_curr - 1);

        sum += fib_curr;

        if (!(n > 0)) {
            break;
        }

        temp = fib_curr;
        fib_curr = fib_prev + fib_curr;
        fib_prev = temp;
        n--;

        expected_sum *= 2;
    }

    return 0;
}