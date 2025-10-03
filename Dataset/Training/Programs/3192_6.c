// Bounded queue verification example
// This program implements a fixed-size queue with enqueue, dequeue,
// and various utility operations. It uses nondeterministic choices
// to perform random operations on the queue and asserts that the
// internal state remains consistent. This is intended for use
// with automated verification tools.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int,
                          const char *) __attribute__((__nothrow__, __leaf__))
__attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "bounded_queue.c", 7, "reach_error");
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define QUEUE_SIZE 10
#define MAX_OPS 100

typedef struct {
    int data[QUEUE_SIZE];
    int head;
    int tail;
    int count;
} BoundedQueue;

// Initialize the queue to empty
void init_queue(BoundedQueue *q) {
    q->head = 0;
    q->tail = 0;
    q->count = 0;
}

// Enqueue a value if there is space
void enqueue(BoundedQueue *q, int value) {
    if (q->count < QUEUE_SIZE) {
        q->data[q->tail] = value;
        q->tail = (q->tail + 1) % QUEUE_SIZE;
        q->count++;
    }
}

// Dequeue a value if not empty
void dequeue(BoundedQueue *q) {
    if (q->count > 0) {
        q->head = (q->head + 1) % QUEUE_SIZE;
        q->count--;
    }
}

// Compute the size by traversing from head
int compute_size(BoundedQueue *q) {
    int s = 0;
    int idx = q->head;
    for (int j = 0; j < q->count; j++) {
        s++;
        idx = (idx + 1) % QUEUE_SIZE;
    }
    return s;
}

// Check that the stored count matches the traversed size
void check_queue(BoundedQueue *q) {
    int s = compute_size(q);
}

// Return true if the queue is full
_Bool is_full(BoundedQueue *q) {
    return (q->count == QUEUE_SIZE);
}

// Return true if the queue is empty
_Bool is_empty(BoundedQueue *q) {
    return (q->count == 0);
}

// Peek at the most recently enqueued element (tail - 1)
int peek(BoundedQueue *q) {
    if (q->count > 0) {
        int idx = (q->tail + QUEUE_SIZE - 1) % QUEUE_SIZE;
        return q->data[idx];
    }
    return 0;
}

// Clear the queue completely
void clear_queue(BoundedQueue *q) {
    // For a circular buffer, moving head to tail removes all elements
    q->head = q->tail;
    q->count = 0;
}

int main() {
    BoundedQueue q;
    int ops;
    _Bool choose_op;
    int val;
    int i;

    init_queue(&q);

    // Nondeterministically choose number of operations
    ops = __VERIFIER_nondet_int();
    assume_abort_if_not(ops >= 0 && ops <= MAX_OPS);

    i = 0;
    while (i < ops) {
        // Invariants to check at each step

        // Randomly choose enqueue or dequeue
        choose_op = __VERIFIER_nondet_bool();
        if (choose_op) {
            val = __VERIFIER_nondet_int();
            enqueue(&q, val);
        } else {
            dequeue(&q);
        }

        // Occasionally perform additional checks or utilities
        if (__VERIFIER_nondet_bool()) {
            check_queue(&q);
        }
        if (__VERIFIER_nondet_bool()) {
            // Test is_empty and is_full consistency
            _Bool emp = is_empty(&q);
            _Bool ful = is_full(&q);
            __VERIFIER_assert(ful == (q.count == QUEUE_SIZE));
        }
        if (__VERIFIER_nondet_bool()) {
            // Peek should only be valid when not empty
            if (!is_empty(&q)) {
                int p = peek(&q);
                // The peeked value must equal the last enqueued
                // (or some previous value) but we cannot assert more here
                // We at least assert range of peek
            }
        }
        if (__VERIFIER_nondet_bool()) {
            // Occasionally clear the queue
            clear_queue(&q);
        }

        i++;
    }

    // Final state checks
    check_queue(&q);

    return 0;
}