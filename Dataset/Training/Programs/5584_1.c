#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Simulated external functions
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error(void) { abort(); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Task: Find the least k such that gcd(k, b) = 1 and k > b
void task(int b) {
    int k = b + 1;
    while (gcd(k, b) != 1) {
        k++;
    }
    __VERIFIER_assert(gcd(k, b) == 1);
    printf("Least k such that gcd(k, %d) = 1 and k > %d is: %d\n", b, b, k);
}

int main() {
    int b = __VERIFIER_nondet_int();

    if (b < 2) {
        return 0;
    }

    task(b);

    return 0;
}