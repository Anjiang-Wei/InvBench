/*
  Simulates an incrementing counter until a boundary condition is met
  and checks constraints relevant to counter increments
*/
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "incrementing_counter.c", 6, "reach_error"); }
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
    int x, y, limit;
    x = __VERIFIER_nondet_int();
    limit = __VERIFIER_nondet_int();

    assume_abort_if_not(limit > 0);
    assume_abort_if_not(x >= 0);

    y = x;

    while (counter++ < 10) {
        if (!(y < limit)) {
            break;
        }

        y++;
    }

    __VERIFIER_assert(y >= x);                      // Ensure y has not decremented
    __VERIFIER_assert(y <= x + 10);                 // y should not exceed more than 10 increments from x
    __VERIFIER_assert(y >= limit || counter == 11); // y has either reached the limit or loop ran to completion

    return 0;
}