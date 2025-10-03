#include <assert.h>
#include <stdlib.h>
extern void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * This program simulates a simple inventory management system where
 * we manage a stock level for a product. Both additions and subtractions
 * from the inventory are performed and the constraints are verified at the end.
 */
int main() {
    int stock = 0;
    int max_stock = 100;
    int transactions = __VERIFIER_nondet_int();
    int transaction_limit = 50; // Limiting the number of transactions to avoid infinite loops

    if (transactions <= 0 || transactions >= transaction_limit) {
        return 0;
    }

    for (int i = 0; i < transactions; ++i) {
        int add_stock = __VERIFIER_nondet_int();
        int remove_stock = __VERIFIER_nondet_int();

        if (add_stock < 0 || remove_stock < 0) {
            continue; // Invalid operation, skip
        }

        if (add_stock > 0) {
            int new_stock = stock + add_stock;

            if (new_stock <= max_stock) {
                stock = new_stock;
            }
        }

        if (remove_stock > 0) {
            int new_stock = stock - remove_stock;

            if (new_stock >= 0) {
                stock = new_stock;
            }
        }
    }

    // Verify constraints
    __VERIFIER_assert(stock >= 0 && stock <= max_stock);

    return 0;
}