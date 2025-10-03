#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, c;
    int threshold;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = 0;
    threshold = 100;

    assume_abort_if_not(a >= 0 && a <= 50);
    assume_abort_if_not(b >= 0 && b <= 50);

    while (__VERIFIER_nondet_bool()) {
        if (a > 0) {
            a--;
            c++;
        } else if (b > 0) {
            b--;
            c--;
        }

        // Ensure c never exceeds a threshold
        if (c > threshold) {
            reach_error();
        }

        // Reset c if it goes negative
        if (c < 0) {
            c = 0;
        }
    }

    // Final check to ensure c is within desired bounds
    __VERIFIER_assert(c >= 0 && c <= threshold);

    return 0;
}