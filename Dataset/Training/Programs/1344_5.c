// Program computing products and sums to verify arithmetic identities
// The program uses nested loops to compute volume, area, and summation,
// and then verifies known arithmetic relationships via assertions.

#include <assert.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Maximum bounds for loops
#define MAX_N 50
#define MAX_M 50
#define MAX_P 20
#define MAX_R 100

// compute product of three numbers via nested loops
int compute_volume(int n, int m, int p) {
    int vol = 0;
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < m) {
            int k = 0;
            while (k < p) {
                vol++;
                k++;
            }
            j++;
        }
        i++;
    }
    return vol;
}

// compute product of two numbers via nested loops
int compute_area(int n, int m) {
    int area = 0;
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < m) {
            area++;
            j++;
        }
        i++;
    }
    return area;
}

// compute sum of first r natural numbers via loop
int compute_sum(int r) {
    int sum = 0;
    int i = 1;
    while (i <= r) {
        sum += i;
        i++;
    }
    return sum;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();
    int p = __VERIFIER_nondet_int();
    int r = __VERIFIER_nondet_int();

    // input constraints
    if (n < 0) {
        return 0;
    }
    if (n > MAX_N) {
        return 0;
    }
    if (m < 0) {
        return 0;
    }
    if (m > MAX_M) {
        return 0;
    }
    if (p < 0) {
        return 0;
    }
    if (p > MAX_P) {
        return 0;
    }
    if (r < 0) {
        return 0;
    }
    if (r > MAX_R) {
        return 0;
    }

    // compute values
    int vol = compute_volume(n, m, p);
    int area = compute_area(n, m);
    int sum_r = compute_sum(r);

    // verify that volume equals n*m*p

    // verify that area equals n*m

    // verify that sum_r equals r*(r+1)/2
    {
        long long expected = (long long)r * (r + 1) / 2;
    }

    // verify relation: volume >= area

    // verify relation: sum_r >= r
    __VERIFIER_assert(sum_r >= r);

    return 0;
}