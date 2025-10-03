#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// This program simulates a warehouse with a constraint
// on the number of items stored. Each delivery adds a
// random amount of items, ensuring the stock never falls
// below a threshold.
#define MAX_ITEMS 500
#define MIN_ITEMS 100

int main() {
    int stock = 200;
    int deliveries = 0;
    int max_deliveries = 50;

    // Random deliveries until the warehouse is full or we reach max deliveries
    while (stock < MAX_ITEMS && deliveries < max_deliveries) {
        int new_items = __VERIFIER_nondet_int();
        if (new_items > 0) {
            stock += new_items;
            deliveries++;
        }

        // Ensure the stock doesn't fall below the minimum threshold
        if (stock < MIN_ITEMS) {
        }

        // Prevent overstock
        if (stock > MAX_ITEMS) {
            stock = MAX_ITEMS;
        }
    }

    // After the loop, we expect the stock to be within bounds
    __VERIFIER_assert(stock >= MIN_ITEMS && stock <= MAX_ITEMS);

    return 0;
}