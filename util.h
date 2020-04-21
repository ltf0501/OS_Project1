#ifndef UTIL_H_
#define UTIL_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <unistd.h>
#include <sched.h>

#include <sys/wait.h>
#include <sys/syscall.h>
#include <sys/time.h>

#include <linux/kernel.h>
//#include <linux/linkage.h>
//#include <linux/time.h>

#define kName 32

#define kInf 99

#define UNIT_TIME {volatile unsigned long i; for(i = 0; i < 1000000UL; i++);}

enum Policy {FIFO, RR, SJF, PSJF};

struct Process {
	char name[kName];
	int ready, tot;
	int id;

	int run, ok;
	pid_t pid;
};

int cmp(const void *a, const void *b);
void SetCPU(pid_t pid, int cpu_id);
void Setpri(pid_t pid, int pri);
void DoProcess(struct Process *process);

#endif //UTIL_H_
