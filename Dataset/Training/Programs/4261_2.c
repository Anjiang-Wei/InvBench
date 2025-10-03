#include <stdio.h>

// Function used to simulate a failing condition without stopping the program immediately
void reach_error() { printf("Error: condition failed.\n"); }

// Custom assertion function that prints an error message if the condition is false
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int x = 0;
    int y = 100;

    // Loop that decreases y and increases x concurrently
    while (y > 0) {
        x += 3;
        y -= 5;
    }

    // Check the final state of x and y after the loop
    __VERIFIER_assert(x > y); // After the loop, x should be greater than y

    return 0;
}