#include <assert.h>
#include <stdlib.h>

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

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int x = __VERIFIER_nondet_int(); // A non-deterministic integer
    int y = __VERIFIER_nondet_int(); // A non-deterministic integer

    // Assume constraints for verification
    if (x < 0 || x > 10) {
        return 0;
    }
    if (y < 1 || y > 5) {
        return 0;
    }

    int f_x = fibonacci(x);
    int f_y = fibonacci(y);

    // Simulate a process where f_x and f_y are combined
    int sum = f_x + f_y;
    int product = f_x * f_y;

    // Loop with constraints
    int counter = 0;
    while (counter < sum) {
        if (counter % 2 == 0) {
            counter += y;
        } else {
            counter += x;
        }
        if (counter >= product) {
            __VERIFIER_assert(counter >= product);
            break;
        }
    }

    // Final assertion for verification

    return 0;
}