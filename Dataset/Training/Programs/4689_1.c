/*
Fibonacci Sequence
computes the nth Fibonacci number using iterative approach
checks the nth Fibonacci number for basic properties
returns 1 if the properties are satisfied
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 7, "reach_error"); }
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
    int n, Fibonacci, prev1, prev2, counter;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    if (n == 0) {
        Fibonacci = 0;
    } else if (n == 1) {
        Fibonacci = 1;
    } else {
        prev1 = 1;
        prev2 = 0;
        counter = 2;
        Fibonacci = 1;

        while (1) {
            if (!(counter <= n)) {
                break;
            }

            Fibonacci = prev1 + prev2;
            prev2 = prev1;
            prev1 = Fibonacci;
            counter++;
        }
    }

    // Verify basic properties of Fibonacci numbers
    __VERIFIER_assert(Fibonacci >= 0);

    return 0;
}