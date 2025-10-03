/*
Fibonacci Sequence
computes the first k Fibonacci numbers and stores the sum in variable x.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-ll.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int counter = 0;
int main() {
    int k;
    long long x, a, b, temp, c;
    k = __VERIFIER_nondet_int();

    assume_abort_if_not(k >= 2 && k <= 50); // Ensuring k is within a reasonable range.

    x = 0; // Sum of Fibonacci numbers
    a = 0; // F(0)
    b = 1; // F(1)
    c = 0; // Counter

    while (counter++ < k) {
        temp = a + b; // Calculate next Fibonacci number
        x = x + a;    // Add the current Fibonacci number to the sum
        a = b;        // Move to the next Fibonacci numbers
        b = temp;     // Move the calculated Fibonacci number
        c = c + 1;
        // To prevent the sum from being incorrect via overflow or other issues, an assertion checks non-negative logic
        if (a < 0) {
            __VERIFIER_assert(0);
        }
    }

    // x now holds the sum of the first k Fibonacci numbers
    return 0;
}