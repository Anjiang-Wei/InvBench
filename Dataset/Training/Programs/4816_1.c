#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assume(int condition);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int N, count, sum, temp;

    N = __VERIFIER_nondet_int();
    __VERIFIER_assume(N > 0 && N <= 10);

    count = 0;
    sum = 0;
    temp = N;

    // Calculate the sum of the first N positive even numbers
    while (count < N) {
        // Logging for debugging purposes
        // printf("Current count: %d, Current sum: %d, Current temp: %d\n", count, sum, temp);

        sum += temp * 2;
        count++;
        temp--;
    }

    // Assert that the sum of the first N even numbers is equal to N * (N + 1)
    __VERIFIER_assert(sum == N * (N + 1));

    return 0;
}