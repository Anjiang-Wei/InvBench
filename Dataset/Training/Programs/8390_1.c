extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int();

#define MAX_SIZE 1000

int compute_fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int fib1 = 0, fib2 = 1, fib;
    for (int i = 2; i <= n; ++i) {
        fib = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib;
    }
    return fib2;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n >= MAX_SIZE) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += compute_fibonacci(i);
    }

    // This assertion checks if the calculated sum is non-negative
    __VERIFIER_assert(sum >= 0);

    return 0;
}