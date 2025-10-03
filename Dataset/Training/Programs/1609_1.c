#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    if (n < 0) {
        return 0; // We only consider non-negative n
    }
    if (a < 0 || b < 0) {
        return 0; // a and b must be non-negative
    }

    int result = 0;
    int x = a, y = b;

    while (__VERIFIER_nondet_bool()) {
        if (n <= 0) {
            break;
        }

        if (x > y) {
            x = max(0, x - 2);
            result += x;
        } else {
            y = max(0, y - 2);
            result += y;
        }
        n--;
    }

    __VERIFIER_assert(result >= 0); // Ensure result is non-negative
    return 0;
}