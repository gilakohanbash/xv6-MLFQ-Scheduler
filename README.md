# Multilevel Feedback Queue Scheduler in xv6 (CSCI 350)

This project extends the xv6 operating system by implementing a Multilevel Feedback Queue process scheduler. The scheduler dynamically promotes or demotes processes across priority levels based on CPU usage and responsiveness, improving fairness and interactivity.

> Developed by Gila Kohanbash and Nithin Senthur Jeyamurugan as part of the coursework for *CSCI 350: Operating Systems* at the **University of Southern California**.

---

This project implements a **non-preemptive Multilevel Feedback Queue (MFQ) scheduler** with an **aging mechanism** in the xv6 operating system.

The implementation supports:
- Three priority levels with independent round-robin queues.
- Aging-based **priority boosting** to prevent starvation.
- A new system call `getpinfo()` to extract and log scheduling statistics.
- Three user-level test programs that demonstrate scheduler behavior.
- Timeline graphs that visualize scheduler activity across different workloads.

---

We designed three user-space programs:
| `test1.c` | Mix of I/O-bound and CPU-bound processes |
| `test2.c` | Demonstrates effectiveness of aging and priority boosting |
| `test3.c` | Demonstrates how a process can "game" the scheduler by yielding early |

Each test includes a **timeline graph** showing:
- When processes were scheduled.
- Their queue level.
- Duration of execution.

