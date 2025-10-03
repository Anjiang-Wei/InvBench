// A new C program that demonstrates a reachable condition with state validation

#include <assert.h>
extern void abort(void);
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
        abort();
    }
    }
}

int main() {
    int a, b, c, total;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();
    total = 0;

    assume_abort_if_not(a >= 1 && a <= 10);
    assume_abort_if_not(b >= 1 && b <= 10);
    assume_abort_if_not(c >= 1 && c <= 10);

    while (c > 0) {
        if (a % 2 == 0) {
            total += b;
        } else {
            total += c;
        }

        // Ensure total does not overflow typical bounds

        if (a > b) {
            c -= (a - b);
        } else {
            c--;
        }
    }

    // After loop, total should realistically reflect some computed value
    __VERIFIER_assert(total >= c);

    return 0;
}