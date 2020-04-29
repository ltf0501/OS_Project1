# NTU CSIE OS Project 1 - Process Scheduling
A simple project written with C.

## Enviroment
+ Ubuntu 18.04.4
+ kernel 4.15.0

## New system calls
+ 'asmlinkage void sys\_gettime(struct timespec *r);', id = 333
+ 'asmlinkage void sys\_printinfo(int pid, long a, long b, long c, long d);', id = 334
+ 'asmlinkage void sys\_hello(void);', id = 335

Note that the last system call is just added for testing.

## Execution

```
$make
$sudo ./main
```

The main reads processes' information from stdin, with the following format
```
S // the scheduling policy, one of the following strings: FIFO, RR, SJF, PSJF
N // the number of the processes
N1 R1 T1
N2 R2 T2
...
Nn Rn Tn
// Ni - a character string with a length less than 32 bytes, specifying the name of the i-th process.
//Ri - a non-negative integer, specifying the ready time of the i-th process.
//Ti - a non-negative integer, specifying the execution time of the i-th process.  
```
