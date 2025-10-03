// New C program based on learned patterns and structures

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);
    assume_abort_if_not(c >= 0 && c <= 100);

    int x = 0;
    int y = a;
    int z = b + c;

    while (x < 50) {
        if (y > z) {
            y -= 2;
            z += 1;
        } else {
            y += 1;
            z -= 2;
        }
        x++;
    }

    int w = x + y + z;
    __VERIFIER_assert(w >= (50 + a + b + c - 150));

    return 0;
}