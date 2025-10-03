extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

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

int main() {
    int M, N;
    long long sum, diff;
    M = __VERIFIER_nondet_int();
    N = __VERIFIER_nondet_int();

    assume_abort_if_not(M >= 5 && M <= 20);
    assume_abort_if_not(N >= 5 && N <= 20);

    sum = 0;
    diff = M - N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            sum += i + j;
        }
    }

    // Assert certain conditions about the final values
    __VERIFIER_assert(diff <= M);

    return 0;
}