// This is a small C program designed for automated verification tools.
// The program performs a simple computation to evaluate a mathematical expression
// involving an increment operation. The goal is to meet specific numerical constraints.

extern void abort(void);
void reach_error() { abort(); }

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int x, y, n, result;

    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && x <= 10);
    assume_abort_if_not(y >= 0 && y <= 10);
    assume_abort_if_not(n >= 1 && n <= 5);

    result = 0;

    // Compute the sum of x repeated n times
    // This loop calculates result = x * n
    for (int i = 0; i < n; i++) {
        result += x;
    }

    // Check if the result is equal to x * n

    // Perform a similar calculation with y
    result = 0;

    for (int i = 0; i < n; i++) {
        result += y;
    }

    // Ensure that the result is either y * n or not exceeding 10 * 5 = 50
    __VERIFIER_assert(result == y * n || result <= 50);

    return 0;
}