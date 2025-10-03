#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    // Precondition: Ensure initial values
    if (!(x > 0 && y > 0 && z > 0)) {
        return 0;
    }

    int sum = x + y + z;
    int product = x * y * z;
    int counter = 0;

    // Loop to find the maximum number by comparing with a fixed threshold
    while (sum > 0 && product > 0) {
        if (sum > 50) {
            x += 1;
        } else if (product > 1000) {
            y += 2;
        } else {
            z += 3;
        }
        sum = x + y + z;
        product = x * y * z;
        counter++;

        // Limit the loop to prevent infinite execution
        if (counter > 100) {
            break;
        }
    }

    // Assert that at least one of the conditions is true after the loop
    __VERIFIER_assert(sum > 50 || product > 1000 || counter <= 100);

    return 0;
}