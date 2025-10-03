#include <stdlib.h>

// Simulated verification functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Error reach function
void reach_error() { __assert_fail("0", "auto_generated.c", 5, "reach_error"); }

// Nondeterministic input simulation
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to simulate some resource initialization
void resource_init(int *resource) {
    *resource = __VERIFIER_nondet_int();
    if (*resource < 0) {
        *resource = 0; // normalize to non-negative
    }
}

// Main function with loop and condition checking
int main() {
    int resource1, resource2;
    int x = 0, y = 0;

    // Initializing resources
    resource_init(&resource1);
    resource_init(&resource2);

    // Decision condition based on resources
    if (resource1 > resource2) {
        x = resource1 - resource2;
    } else {
        y = resource2 - resource1;
    }

    // Loop with step adjustment and condition checking
    while (resource1 != resource2) {
        if (resource1 > resource2) {
            resource1--;
            x++;
        } else {
            resource2--;
            y++;
        }

        // Safety condition: maintain balanced steps
        if (__VERIFIER_nondet_bool()) {
            __VERIFIER_assert((x == y && resource1 == resource2) || (x != y));
        }
    }

    // Final condition checking
    if (resource1 == resource2) {
    }

    return 0;
}