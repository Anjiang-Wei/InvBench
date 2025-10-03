#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Reach error\n");
    abort();
}
void assume_abort_if_not(int cond) {
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

// Function to simulate a nondeterministic integer
int __VERIFIER_nondet_int() {
    return rand();
}

int main() {
    int x, y, sum, count;
    x = 0;
    y = 0;
    sum = 0;
    count = __VERIFIER_nondet_int() % 100; // Limit count to a realistic value

    int i = 0;
    while (i < count) {
        x += i;
        y += i * i;
        sum += x + y;
        i++;
    }

    // Ensure that sum is non-negative, as all operations involve additions of non-negative numbers
    __VERIFIER_assert(sum >= 0);

    printf("Final values: x = %d, y = %d, sum = %d, count = %d\n", x, y, sum, count);
    return 0;
}