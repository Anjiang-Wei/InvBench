// SPDX-License-Identifier: Apache-2.0

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "summation.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    int n, sum = 0;
    int currentValue;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0);

    for (int i = 0; i < n; i++) {
        currentValue = __VERIFIER_nondet_int();
        assume_abort_if_not(currentValue > 0); // ensuring positive integers for summation
        sum += currentValue;
    }

    // Assuming the summation should not overflow for this context
    // Under the condition that sum should be non-negative given the assumptions.
    __VERIFIER_assert(sum >= 0);

    return 0;
}