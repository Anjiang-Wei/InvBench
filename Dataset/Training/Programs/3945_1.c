extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    // Initialize variables
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = 0;
    int w = 0;

    // Assume initial conditions for x and y
    assume_abort_if_not(x >= 0 && x <= 10);
    assume_abort_if_not(y >= 0 && y <= 10);

    // Loop to compute z based on some condition involving x and y
    int i = 0;
    while (i < 10) {
        if (x % 2 == 0) {
            z = z + x;
        } else {
            z = z - y;
        }
        x = x + 1;
        y = y - 1;
        i++;
    }

    // Postcondition: z should be an integer within certain bounds
    __VERIFIER_assert(z >= -100 && z <= 100);

    // Additional loop with a logical constraint involving w
    while (w < 10) {
        w = w + 1;
    }

    return 0;
}