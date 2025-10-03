// Program computing triangular numbers and sum of squares

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "tri_sumsq.c", 5, "reach_error");
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

int counter = 0;

int main() {
    int k = __VERIFIER_nondet_int();
    long long i = 0;
    long long t = 0; // t will hold the triangular number sum_{j=0..i-1} j
    long long s = 0; // s will hold the sum of squares sum_{j=0..i-1} j^2

    while (counter++ < 100) {
        // Invariants we expect to hold at the start of each iteration

        // Stop when we've done k steps
        if (!(i < k)) {
            break;
        }

        // Update the sums and index
        s = s + i * i;
        t = t + i;
        i = i + 1;
    }

    // Check invariants one last time after the loop
    __VERIFIER_assert(2 * t == i * (i - 1));

    return 0;
}