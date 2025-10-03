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
  The program models a simplified resource allocation scenario. Resources 'r' are allocated
  to 'n' projects such that each project gets an equal or nearly equal share.
  - 'r' must always be positive while allocation.
  - The number of fully allocated projects should be as expected by an upper constraint.
  - No individual project allocation should exceed its share.
*/
int main() {
    int r = __VERIFIER_nondet_int(); // total resources
    int n = __VERIFIER_nondet_int(); // number of projects
    int allocated = 0;               // resources allocated
    int count_projects = 0;          // number of projects allocated

    if (r <= 0 || n <= 0) {
        return 0;
    }

    while (allocated < r && count_projects < n) {
        int allocation_per_project = r / n;
        if (__VERIFIER_nondet_bool()) {
            allocation_per_project++; // allow slightly uneven distribution if resources are indivisible
        }
        if (allocation_per_project > r - allocated) {
            allocation_per_project = r - allocated; // cap allocation to remaining resources
        }
        allocated += allocation_per_project;
        count_projects++;
    }

    // Post conditions to verify
    __VERIFIER_assert(count_projects <= n);

    return 0;
}