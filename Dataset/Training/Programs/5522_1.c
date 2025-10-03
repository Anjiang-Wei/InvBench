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

int main() {
    int a = 0, b = 10, c = 0;

    // Simulate some resource increase until a certain threshold
    while (a < 100) {
        // Simulate a condition based on which we increment 'c'
        if (a % 3 == 0 && a % 7 == 0) {
            c++;
        }
        a++;
    }

    // After the first loop, ensure 'c' has increased correctly
    __VERIFIER_assert(c == 5);

    // Reset `c` and decrease b in another loop
    c = 0;
    while (b > 0) {
        // Every even step decrement 'c'
        if (b % 2 == 0) {
            c++;
        }
        b--;
    }

    // Ensure the operation logic on 'c' is consistent

    return 0;
}