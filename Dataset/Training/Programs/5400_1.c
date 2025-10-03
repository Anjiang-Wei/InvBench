#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Error reached\n");
    exit(1);
}

extern unsigned int __VERIFIER_nondet_uint(void);
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

#define LIMIT 200

int main() {
    unsigned int sum = 0;
    unsigned int num;
    unsigned int iter = 0;

    // Simulating external input
    for (unsigned int i = 0; i < 10; i++) {
        num = __VERIFIER_nondet_uint();
        if (num > 10) {
            continue; // assume we handle only inputs 0-10
        }

        iter++;
        sum += num * num;

        if (sum >= LIMIT) {
            break;
        }
    }

    __VERIFIER_assert(sum < LIMIT || iter <= 10);

    printf("Computation completed. Sum: %u\n", sum);

    return 0;
}