// SPDX-FileContributor: OpenAI Assistant
// SPDX-License-Identifier: Apache-2.0

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_example.c", 3, "reach_error"); }

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
    unsigned int a = 0;
    unsigned int b = 10;
    unsigned int c = 1;
    unsigned int d = 1;

    while (a < b) {
        c += d; // Increment c by the current value of d
        d *= 2; // Double d each iteration
        a++;
    }

    // Verifying a property after loop execution
    __VERIFIER_assert(c != 43); // This assertion expects c never to be 43

    return 0;
}