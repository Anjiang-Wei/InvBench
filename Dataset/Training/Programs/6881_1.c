#include <assert.h>
#include <stdlib.h>
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// The program utilizes a simple simulation of checking balance between two containers
// Both containers initially have zero items, and items can be transferred between them
// while ensuring that any container is not overfilled beyond a threshold limit.

#define THRESHOLD 50

typedef struct Container {
    int items;
} Container;

// Function to transfer items from one container to another
void transfer(Container *from, Container *to, int amount) {
    if (from->items >= amount && to->items + amount <= THRESHOLD) {
        from->items -= amount;
        to->items += amount;
    }
}

int main() {
    Container A = {0};
    Container B = {0};

    int operations = __VERIFIER_nondet_int();
    if (operations < 0) {
        return 0;
    }

    while (operations--) {
        int amount = __VERIFIER_nondet_int();
        if (amount < 0) {
            amount = -amount; // ensure non-negative amounts
        }

        // Randomly decide whether to transfer from A to B or B to A
        if (__VERIFIER_nondet_int() % 2 == 0) {
            transfer(&A, &B, amount);
        } else {
            transfer(&B, &A, amount);
        }

        // Check that no container exceeds its capacity
        __VERIFIER_assert(A.items <= THRESHOLD && B.items <= THRESHOLD);
    }

    // Final verification that both containers are within limits
    return 0;
}