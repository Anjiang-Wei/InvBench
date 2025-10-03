#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_program.c", 3, "reach_error"); }

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

// Program to simulate scenario with resource counting
int main() {
    int resource = 0;
    int max_resource = 100;
    int operation_choice;
    int operations_count = 0;
    int max_operations = __VERIFIER_nondet_int();

    if (max_operations <= 0) {
        return 0; // Invalid max_operations
    }

    while (operations_count < max_operations) {
        operation_choice = __VERIFIER_nondet_int();

        switch (operation_choice) {
        case 0: // Increase resource
            if (resource < max_resource) {
                resource++;
            }
            break;

        case 1: // Decrease resource
            if (resource > 0) {
                resource--;
            }
            break;

        case 2: // Double resource
            if (2 * resource <= max_resource) {
                resource *= 2;
            }
            break;

        default: // No operation
            break;
        }

        operations_count++;
    }

    // Verify resources are within bounds at the end
    __VERIFIER_assert(resource >= 0 && resource <= max_resource);

    return 0;
}