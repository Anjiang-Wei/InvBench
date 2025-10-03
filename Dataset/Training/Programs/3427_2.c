extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 5, "reach_error"); }
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
    int a = 0;
    int b = __VERIFIER_nondet_int();        // Non-deterministic integer
    assume_abort_if_not(b > 0 && b < 1000); // Assume b is within a reasonable range

    int sum = 0;
    int prod = 1;
    int limit = 10;

    int i = 0;
    while (i < limit) {
        sum += a;
        prod *= b;

        a += 1;

        __VERIFIER_assert(prod >= b);

        if (a > 50) { // Arbitrary stopping condition for demonstration
            break;
        }

        i++;
    }

    return 0;
}