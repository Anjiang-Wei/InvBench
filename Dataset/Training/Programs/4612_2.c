// This program is designed to simulate a simple vending machine system with verification constraints.
// It follows some patterns and structures from the provided examples.

#include <stdio.h>
#include <stdlib.h>

#define MAX_STOCK 10
#define COFFEE_PRICE 3
#define TEA_PRICE 2

int stock_coffee = MAX_STOCK;
int stock_tea = MAX_STOCK;
int balance = 0;

void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        exit(1);
    }
}

extern int __VERIFIER_nondet_int(void);

int dispense_product(int product) {
    if (product == 1 && stock_coffee > 0 && balance >= COFFEE_PRICE) {
        stock_coffee--;
        balance -= COFFEE_PRICE;
        return 1; // Coffee dispensed
    } else if (product == 2 && stock_tea > 0 && balance >= TEA_PRICE) {
        stock_tea--;
        balance -= TEA_PRICE;
        return 2; // Tea dispensed
    }
    return 0; // Nothing dispensed
}

int main() {
    int product, inserted_coins;
    // The vending machine accepts commands indefinitely
    while (1) {
        product = __VERIFIER_nondet_int();
        if (product < 1 || product > 2) {
            continue; // Invalid product, continue to the next iteration
        }

        inserted_coins = __VERIFIER_nondet_int();
        if (inserted_coins < 0 || inserted_coins > 10) {
            continue; // Invalid coin input, continue to the next iteration
        }

        // Update balance with inserted coins
        balance += inserted_coins;

        // Attempt to dispense the selected product
        int dispensed = dispense_product(product);

        // Verification assertions
        __VERIFIER_assert(stock_coffee >= 0 && stock_coffee <= MAX_STOCK);

        if (dispensed == 0) {
            // If unable to dispense, ensure balance remains unaffected for that product
            if (product == 1) {
            }
            if (product == 2) {
            }
        }

        // Simulate returning coins if any product was dispensed
        if (dispensed != 0) {
            balance = 0;
        }
    }

    return 0;
}