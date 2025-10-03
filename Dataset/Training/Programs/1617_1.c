/*
  Fibonacci Sequence Generator
  Computes Fibonacci numbers up to a specified limit
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 7, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int max_steps;
    unsigned int n1, n2, next, c;

    max_steps = __VERIFIER_nondet_uint();
    assume_abort_if_not(max_steps <= 20); // Limiting for verification purposes

    n1 = 0;
    n2 = 1;
    c = 0;

    while (1) {
        __VERIFIER_assert((c == 0 && n1 == 0) || (c == 1 && n2 == 1) || (c >= 2 && n2 == n1 + n2 - n1)); // Simple Fibonacci property

        if (!(c <= max_steps)) {
            break;
        }

        next = n1 + n2;
        n1 = n2;
        n2 = next;
        c++;

        // Check property of Fibonacci: Fibonacci(n) should stay non-negative
    }
}