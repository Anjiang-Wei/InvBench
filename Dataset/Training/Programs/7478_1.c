// 2x2 Magic Square Unsatisfiable Verification Task
// -------------------------------------------------
//
// This program attempts to model the 2x2 magic square problem:
//    a  b
//    c  d
//
// Subject to the following constraints:
//   1) a, b, c, d are integers in the domain [1..4]
//   2) All four values a, b, c, d are pairwise distinct
//   3) The sums of the two rows are equal:    a + b == c + d
//   4) The sums of the two columns are equal: a + c == b + d
//
// It is well known that no 2x2 magic square with distinct entries 1..4 exists.
// Therefore, the function solve_magic2x2(a,b,c,d) should always return 0.
// The program asserts at the end that no valid assignment is possible.
//
// This file is designed to be processed by automated verification tools
// (e.g., software model checkers) to prove that the assertion can never fail.

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "magic2x2.c", 15, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// -------------------------------------------------
// Check if an integer x is within the allowed domain [1..4].
// Returns 1 if true, 0 otherwise.
// -------------------------------------------------
int check_domain(int x) {
    if (x >= 1 && x <= 4) {
        return 1;
    }
    return 0;
}

// -------------------------------------------------
// Check that all values in the array arr[] of size 4
// are pairwise distinct.
// Returns 1 if all distinct, 0 if any duplicates.
// -------------------------------------------------
int check_distinct(int arr[4]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 4; j++) {
            if (arr[i] == arr[j]) {
                return 0;
            }
        }
    }
    return 1;
}

// -------------------------------------------------
// Solve the 2x2 magic square constraints.
// a, b, c, d are four integers.
// Returns 1 if all constraints are satisfied, 0 otherwise.
// -------------------------------------------------
int solve_magic2x2(int a, int b, int c, int d) {
    int arr[4];
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;

    // 1) Domain checks
    if (!check_domain(a)) {
        return 0;
    }
    if (!check_domain(b)) {
        return 0;
    }
    if (!check_domain(c)) {
        return 0;
    }
    if (!check_domain(d)) {
        return 0;
    }

    // 2) Distinctness check
    if (!check_distinct(arr)) {
        return 0;
    }

    // 3) Row sums equality: a + b == c + d
    if (a + b != c + d) {
        return 0;
    }

    // 4) Column sums equality: a + c == b + d
    if (a + c != b + d) {
        return 0;
    }

    // If all checks pass, we have a valid 2x2 magic square
    return 1;
}

// -------------------------------------------------
// Main function: obtain nondeterministic inputs,
// bound them to avoid overflow issues, and assert
// that no 2x2 magic square exists.
// -------------------------------------------------
int main() {
    int a, b, c, d;

    // Obtain nondeterministic values for the four entries
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();
    d = __VERIFIER_nondet_int();

    // For safety, assume they lie within a reasonable range
    // to prevent unintended overflow in the checks.
    assume_abort_if_not(a >= -1000 && a <= 1000);
    assume_abort_if_not(b >= -1000 && b <= 1000);
    assume_abort_if_not(c >= -1000 && c <= 1000);
    assume_abort_if_not(d >= -1000 && d <= 1000);

    // Evaluate the solver for the 2x2 magic square problem
    int res = solve_magic2x2(a, b, c, d);

    // Assert that no solution exists, i.e., solve_magic2x2 must always be 0
    __VERIFIER_assert(res == 0);

    return 0;
}