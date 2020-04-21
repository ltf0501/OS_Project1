#include "util.h"

int cmp(const void *a, const void *b) {
	const struct Process *p1 = (const struct Process *)a;
	const struct Process *p2 = (const struct Process *)b;

	if(p1->ready != p2->ready) {
		return p1->ready < p2->ready ? -1 : 1;
	}
	if(p1->id != p2->id) {
		return p1->id < p2->id ? -1 : 1;
	}
	return 0;
}

void Setpri(pid_t pid, int pri) {
	struct sched_param p;
	p.sched_priority = pri;
	if(sched_setscheduler(pid, SCHED_FIFO, &p)) {
		fprintf(stderr, "set priority error\n");
		exit(1);
	}
}

void SetCPU(pid_t pid, int cpu_id) {
	cpu_set_t cpu;
	CPU_ZERO(&cpu);
	CPU_SET(cpu_id, &cpu);

	if(sched_setaffinity(pid, sizeof(cpu), &cpu)) {
		fprintf(stderr, "sched_setaffinity error\n");
		exit(1);
	}
}

void DoProcess(struct Process *process) {
	pid_t pid = fork();
	if(pid < 0) {
		fprintf(stderr, "fork error\n");
		exit(1);
	}
	if(pid == 0) { // child
		struct timeval start, end;
		//struct timespec start, end;
		gettimeofday(&start, NULL);
		//getnstimeofday(&start);
		for(int j = 0; j < process->tot; j++)
			UNIT_TIME;
		gettimeofday(&end, NULL);
		//getnstimeofday(&end);
		//printk(KERN_INFO "[Project 1] %d %ld.%09ld %ld.%09ld\n", getpid(), start.tv_sec, start.tv_nsec, end.tv_sec, end.tv_nsec);
		fprintf(stderr, "[Project 1] %d %ld.%09ld %ld.%09ld\n", getpid(), start.tv_sec, start.tv_usec, end.tv_sec, end.tv_usec);
		exit(0);
	}
	else { // father
		Setpri(pid, 1);	
		SetCPU(pid, 1);

		process->pid = pid;
		process->run = 0;
		process->ok = 1;

		printf("%s %d\n", process->name, process->pid);
		fflush(stdout);
	}
}
