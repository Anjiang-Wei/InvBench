/*
 * A new C program inspired by the provided examples.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
}
void *malloc(unsigned int size);

int N;

int main() {
    N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 1000);

    int i;
    int error_count = 0;
    int *data = malloc(sizeof(int) * N);
    for (i = 0; i < N; i++) {
        data[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(data[i] >= 0 && data[i] <= 10);
    }

    for (i = 0; i < N; i++) {
        // Simulate a condition check leading to an error count update
        if (data[i] >= 5) {
            error_count++;
        }
    }

    // Check some logical constraints about error_count
    __VERIFIER_assert(error_count >= 0);
    return 0;
}