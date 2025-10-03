extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int();

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int t;

    if (a > 100 || b > 100 || c > 100) {
        return 0;
    }

    // Perform bubble sort on a small set of numbers
    if (a > b) {
        t = a;
        a = b;
        b = t;
    }
    if (b > c) {
        t = b;
        b = c;
        c = t;
    }
    if (a > b) {
        t = a;
        a = b;
        b = t;
    }

    // Introducing a loop to simulate repeating a calculation with a condition
    int x = 0;
    int sum = 0;
    while (x < 50) {
        sum += x;
        x++;
    }

    // Verify the correctness of the sort and sum calculation
    __VERIFIER_assert(a <= b);
}