// A program that sums the square of numbers until a condition is met and checks a property.

#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool();

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n = 0, sum = 0, limit;
    limit = __VERIFIER_nondet_int();

    // Assume the limit is a reasonable positive number
    if (limit <= 0 || limit >= 1000) {
        return 0;
    }

    while (n < limit) {
        int next_value = n + 1;
        sum += next_value * next_value;

        __VERIFIER_assert(sum >= 0); // Ensuring sum never becomes negative

        if (__VERIFIER_nondet_bool()) {
            if (sum > 10000) {
                sum = 0;
            }
        }
        n++;
    }
}