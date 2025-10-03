/*
Fibonacci Sequence
This program computes Fibonacci numbers and contains verification assertions
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-ll.c", 4, "reach_error"); }
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
    int n;
    long long a, b, temp;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    a = 0;
    b = 1;

    int i = 0;
    while (1) {

        if (!(i < n)) {
            break;
        }

        temp = a + b;
        a = b;
        b = temp;
        i = i + 1;
    }

    __VERIFIER_assert(b >= a && a >= 0);
}