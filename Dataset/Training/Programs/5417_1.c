#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern void abort(void);
int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 50); // Restrict the value of N for demonstration

    int prime_count = 0;
    int i = 2;

    while (i < N) {
        if (is_prime(i)) {
            prime_count++;
        }
        i++;
    }

    __VERIFIER_assert(prime_count >= 0);
    return 0;
}