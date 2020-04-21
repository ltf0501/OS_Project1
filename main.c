#include "main.h"

#include "FIFO.h"
#include "RR.h"
#include "SJF.h"
#include "PSJF.h"

enum Policy Get() {
	char policy[6];
	assert(scanf("%s", policy) == 1);

	if(strcmp(policy, "FIFO") == 0) return FIFO;
	if(strcmp(policy, "RR") == 0) return RR;
	if(strcmp(policy, "SJF") == 0) return SJF;
	if(strcmp(policy, "PSJF") == 0) return PSJF;

	fprintf(stderr, "Unknown policy: %s\n", policy);
	exit(1);
}
int main() {
	enum Policy policy = Get();

	int n;
	assert(scanf("%d", &n) == 1);
	struct Process process[n];
	memset(process, 0, sizeof(process));

	for(int i = 0; i < n; i++) {
		assert(scanf("%s%d%d", process[i].name, &process[i].ready, &process[i].tot));
		process[i].id = i;
	}

	qsort((void *)process, n, sizeof(struct Process), cmp);

	SetCPU(getpid(), 0);

	if(policy == FIFO) FIFO_Scheduler(process, n);
	if(policy == RR) RR_Scheduler(process, n);
	if(policy == SJF) SJF_Scheduler(process, n);
	if(policy == PSJF) PSJF_Scheduler(process, n);

	return 0;
}
