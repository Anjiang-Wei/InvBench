// This is a new C program illustrating the structure and logic
// inspired by the provided examples.

/* External function declarations */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

/* Reach error allows the program to fail gracefully if something goes wrong */
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

/* Function to assert conditions, reaching an error if the condition is false */
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

/* Main function implementing computational logic */
int main() {
    int n = 0, sum = 0;
    int max = 50; // Define a maximum value up to which we sum the squares

    while (n < max) {
        sum += n * n; // Calculate the sum of squares
        n++;
    }

    /* Validate that the sum behaves as expected */
    __VERIFIER_assert(sum >= 0);

    /* Final assert to ensure the loop processed correctly */

    return 0;
}