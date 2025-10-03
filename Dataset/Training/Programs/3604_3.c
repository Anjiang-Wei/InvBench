#include <assert.h>
extern void reach_error(void);
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int max_candies = __VERIFIER_nondet_int();
    int person1 = 0, person2 = 0, total_candies = 0;

    // Assume reasonable bounds
    if (!(max_candies >= 10 && max_candies <= 100)) {
        return 0;
    }

    // Distribute candies equally between two people
    for (int i = 0; i < max_candies; i++) {
        if (i % 2 == 0) {
            person1++;
        } else {
            person2++;
        }
        total_candies++;
    }

    // Check constraints and properties
    __VERIFIER_assert(person1 == person2 || person1 - person2 == 1);

    return 0;
}