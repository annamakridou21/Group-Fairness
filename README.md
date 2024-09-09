## Table of Contents

- [Group-Fairness](#group-fairness)

- [Implementation](#implementation)

# Group-Fairness
In my Group Fairness policy processes are assigned CPU time based on their group. I have added two new system calls, set_task_params and get_task_params to ensure equal distribution of CPU time across process groups.

# Implementation
For the implementation of this exercise on the host OS, I have modified sched.h to include the new fields in the task_struct. Additionally, I created a new header in linux/include named mystruct.h, which contains the definition of the d_params structure. On the guest OS, I have created three test cases and modified unistd to include the necessary definitions required for the tests to run.

