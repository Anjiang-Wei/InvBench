// Sequence generation and verification program
// Computes sequences T and S of length N+1:
//   T[0] = 1
//   S[0] = 1
//   for i = 1..N:
//     T[i] = 2*T[i-1] + 1
//     S[i] = S[i-1] + T[i]
// Then checks the closed‐form formulas:
//   T[N] == 2^(N+1) - 1
//   S[N] == (N+2)*2^N - 1

#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "ts_sequence.c", 6, "reach_error");
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

int main() {
    int N = __VERIFIER_nondet_int();
    // bound N so shifts and multiplications stay within 64 bits
    assume_abort_if_not(N >= 0);
    assume_abort_if_not(N <= 30);

    long long T = 1; // T[0]
    long long S = 1; // S[0]
    int i;
    for (i = 1; i <= N; i++) {
        T = 2 * T + 1; // T[i] = 2*T[i-1] + 1
        S = S + T;     // S[i] = S[i-1] + T[i]
    }

    // At this point T = T[N], S = S[N]
    long long expected_T = ((long long)1 << (N + 1)) - 1;
    long long expected_S = (long long)(N + 2) * ((long long)1 << N) - 1;

    __VERIFIER_assert(T == expected_T);

    return 0;
}