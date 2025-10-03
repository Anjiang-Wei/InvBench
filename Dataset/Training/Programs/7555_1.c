// Mathematical Summation with Conditional Logic and Constraints

#include <assert.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { assert(0); }
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
    }
    }
    return;
}

int main() {
    int n, a, limit;
    long sum = 0;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100); // Constraint on 'n'
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1 && a <= 10); // Constraint on 'a'
    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit >= 10 && limit <= 100); // Constraint on repetition 'limit'

    int count = 0;
    int i = 0;

    // Loop through integers and perform summation under constraints
    while (i < limit) {
        if (i % a == 0) { // A meaningful constraint: only sum if index is divisible by 'a'
            sum += i;
            count++;
        }
        i++;
    }

    __VERIFIER_assert(n * sum >= 0); // Ensure n multiplied by sum does not go negative which is trivially true
    return 0;
}