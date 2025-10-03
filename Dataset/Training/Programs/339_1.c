extern void abort(void);
extern int __VERIFIER_nondet_int();
void reach_error() {
    char *p = 0;
    *p = 0;
} // deliberately cause a segmentation fault

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 1000); // assuming some sensible bounds

    int sum = 0;
    int i;

    for (i = 1; i <= n; i++) {
        sum += i;
        // This invariant doesn't hold: i*(i + 1)/2 == sum, deliberately adding a slight disorder
        __VERIFIER_assert(sum <= (i * (i + 1)) / 2);
    }

    // Post-loop, verify the partial sum (Triangular number formula)

    return 0;
}