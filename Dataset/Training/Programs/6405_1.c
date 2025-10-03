// New C program based on learned patterns

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
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= -50 && a <= 50);
    assume_abort_if_not(b >= -50 && b <= 50);

    int c = 0;
    unsigned int loop_counter = 0;

    while (loop_counter < 100) {
        if (a > b) {
            c = c + a - b;
        } else {
            c = c + b - a;
        }

        a += 2;
        b -= 1;
        loop_counter++;
    }

    // Ensure we've reached an expected balance point
    __VERIFIER_assert(c > 0);

    return 0;
}