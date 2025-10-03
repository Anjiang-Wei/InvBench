/*
Fibonacci Sequence
Computes the Fibonacci sequence up to the nth number
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n;
    long long a = 0, b = 1, next = 0;
    int counter = 0;

    n = __VERIFIER_nondet_int();           // Assume n is nondeterministic but positive
    assume_abort_if_not(n > 0 && n <= 92); // Limits to prevent overflow in Fibonacci calculations

    while (counter < n) {
        if (counter == 0) {
            next = 0;
        } else if (counter == 1) {
            next = 1;
        } else {
            next = a + b;
            a = b;
            b = next;
        }
        counter++;
    }

    // The nth Fibonacci number should be less than or equal to 7540113804746346429
    // This is the maximum value for n=92, making sure there's no overflow in 'next'
    __VERIFIER_assert(next <= 7540113804746346429);

    return 0;
}