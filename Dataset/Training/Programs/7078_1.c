// This program is part of a collection for demonstrating program verification.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "integer_relation.c", 9, "reach_error"); }
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
    int a, b, c, i;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    assume_abort_if_not(b >= 1);
    i = 0;
    int sum_a = 0;
    int sum_b = 0;

    while (i < 100) {
        sum_a += a;
        sum_b += b;
        __VERIFIER_assert(sum_a * b - sum_b * a == 0); // Ensures linear proportionality between sums

        if (!(i < c)) {
            break;
        }

        i++;
    }
}