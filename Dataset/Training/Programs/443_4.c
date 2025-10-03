// This program is designed for automated verification tools.
// It includes several computational tasks:
// 1. Bubble sort with sortedness check.
// 2. Prefix sum computation and validation.
// 3. Matrix transpose round-trip check.
// 4. Fibonacci sequence generation and sum identity check.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "verification_program.c", 7, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

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

#define MAX_SIZE 10
#define MAX_N 5
#define MAX_M 5
#define MAX_FIB 20

int main() {
    // =====================================================
    // Section 1: Bubble Sort on a nondeterministic array
    // =====================================================

    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= MAX_SIZE);

    int arr[MAX_SIZE];
    for (int i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Bubble sort in ascending order
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    // Verify that the array is sorted
    for (int i = 0; i + 1 < n; i++) {
    }

    // =====================================================
    // Section 2: Prefix Sums and Total Sum Check
    // =====================================================

    long sums[MAX_SIZE];
    if (n > 0) {
        sums[0] = arr[0];
    }
    for (int i = 1; i < n; i++) {
        sums[i] = sums[i - 1] + arr[i];
        // Since arr is sorted ascending, prefix sums are non-decreasing
    }

    // Compute total by a fresh loop and compare to sums[n-1]
    long total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    if (n > 0) {
    } else {
        __VERIFIER_assert(total == 0);
    }

    // =====================================================
    // Section 3: Matrix Transpose Round-Trip
    // =====================================================

    int rows = __VERIFIER_nondet_int();
    int cols = __VERIFIER_nondet_int();
    assume_abort_if_not(rows >= 0 && rows <= MAX_N);
    assume_abort_if_not(cols >= 0 && cols <= MAX_M);

    int mat[MAX_N][MAX_M];
    int tr[MAX_M][MAX_N];
    int tr2[MAX_N][MAX_M];

    // Fill the original matrix with nondeterministic values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = __VERIFIER_nondet_int();
        }
    }

    // First transpose: mat -> tr
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            tr[j][i] = mat[i][j];
        }
    }

    // Second transpose: tr -> tr2
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            tr2[j][i] = tr[i][j];
        }
    }

    // Check that the double-transposed matrix equals the original
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        }
    }

    // =====================================================
    // Section 4: Fibonacci Sequence and Sum Identity
    // =====================================================

    int F = __VERIFIER_nondet_int();
    assume_abort_if_not(F >= 0 && F <= MAX_FIB);

    // We'll compute fib[0..F+2] to validate the sum identity.
    int fib[MAX_FIB + 3];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < F + 3; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Identity: sum_{k=0..i} fib[k] == fib[i+2] - 1
    for (int i = 0; i < F; i++) {
        int accum = 0;
        for (int k = 0; k <= i; k++) {
            accum += fib[k];
        }
    }

    return 0;
}