extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern void abort(void);

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
    int n = __VERIFIER_nondet_int();
    if (n <= 0 || n > 100) {
        return 0; // Limit the range for simplicity
    }

    int x = 0;
    int sum_of_squares = 0;
    int sum_of_odds = 0;

    while (x < n) {
        if (x % 2 == 0) {
            sum_of_squares += x * x;
        } else {
            sum_of_odds += x;
        }
        x++;
    }

    // Verify some condition related to the loop calculations
    // For this logic, we'll assert that sum_of_squares should be greater than sum_of_odds if n is large enough
    if (n > 5) {
        __VERIFIER_assert(sum_of_squares > sum_of_odds);
    }

    return 0;
}