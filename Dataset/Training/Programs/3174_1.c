// sumcubes-ll.c
// Computes the sum of cubes of the first k natural numbers
// and checks the identity: 1^3 + 2^3 + ... + k^3 == (1 + 2 + ... + k)^2

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sumcubes-ll.c", 8, "reach_error");
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
    return;
}

int main() {
    int k;
    long long i, sum, cubesum;

    // nondeterministic input for k
    k = __VERIFIER_nondet_int();
    // bound k to avoid overflow
    assume_abort_if_not(k >= 0);
    assume_abort_if_not(k <= 1000);

    i = 1;
    sum = 0;
    cubesum = 0;

    // compute sum = 1 + 2 + ... + k
    //         cubesum = 1^3 + 2^3 + ... + k^3
    while (1) {
        if (!(i <= k)) {
            break;
        }
        sum = sum + i;
        cubesum = cubesum + i * i * i;
        i = i + 1;
    }

    // check the well-known identity: sum of cubes = (sum of naturals)^2
    __VERIFIER_assert(cubesum == sum * sum);

    return 0;
}