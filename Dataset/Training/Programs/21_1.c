#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Sequence Generator
Computes the Fibonacci sequence values under a given limit
and verifies a basic property of Fibonacci numbers.

names= f1 f2
precondition= n > 0
loopcondition= f2 <= n
loop= { int temp = f2; f2 = f1 + f2; f1 = temp; count++; }
postcondition= count >= 2 && (f1 + f2) <= (n * 2)
learners=non-linear
*/
int main() {
    int n = __VERIFIER_nondet_int(); // Limit up to which Fibonacci numbers are generated
    if (!(n > 0)) {
        return 0;
    }

    int f1 = 0;    // First Fibonacci number
    int f2 = 1;    // Second Fibonacci number
    int count = 0; // To keep track of how many Fibonacci numbers are generated

    while (f2 <= n) {
        __VERIFIER_assert(f2 >= f1); // Using that Fibonacci numbers are non-decreasing

        int temp = f2;
        f2 = f1 + f2;
        f1 = temp;
        count++;
    }
}