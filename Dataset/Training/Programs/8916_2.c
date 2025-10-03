/* program to find the greatest power of two that divides a given number */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "power_of_two_divisor.c", 5, "reach_error"); }
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
    int number = __VERIFIER_nondet_int();
    int power_of_two = 1;

    assume_abort_if_not(number > 0);

    while ((number & 1) == 0) {
        number = number >> 1;
        power_of_two = power_of_two << 1;
    }

    // At this point, 'power_of_two' should be the greatest power of two that divides the original 'number'
    __VERIFIER_assert((power_of_two & (power_of_two - 1)) == 0); // Ensure 'power_of_two' is indeed a power of two
    return 0;
}