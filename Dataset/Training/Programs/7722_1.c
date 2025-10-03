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

int main() {
    int a = 0, b = 0, c = 0;
    int limit = __VERIFIER_nondet_int();

    // Ensure limit is a positive number
    if (limit <= 0) {
        abort(); // terminate the program if the assumption is not met
    }

    while (a < limit) {
        a++;

        if (__VERIFIER_nondet_int() % 2 == 0) {
            // Simulate some logic
            b += 2;
        } else {
            c += a;
        }
    }

    // Verify some condition at the end
    __VERIFIER_assert(b + c > 0);

    return 0;
}