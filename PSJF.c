#include "PSJF.h"

void PSJF_Scheduler(struct Process *process, int n) {
	int count = 0, in_heap = 0;
	struct Process *cur = NULL;

	struct Process **HeapPool = calloc(n + 1, sizeof(struct Process *)); 
	//struct Process* HeapPool[kMaxNode];
		
	for(int time = 0; ; time++) {
		while(count < n && process[count].ready <= time) {
			Insert(HeapPool, ++in_heap, &process[count]);
			count++;

			if(cur && in_heap) {
				if(CompareNode(HeapPool[1], cur)) {
					struct Process *p = HeapPool[1];
					Delete(HeapPool, in_heap--);

					Setpri(cur->pid, 1);
					Insert(HeapPool, ++in_heap, cur);

					cur = p;
					Setpri(cur->pid, kInf); 
				}
			} 
		} 

		if(!cur && in_heap) {
			cur = HeapPool[1];
			Delete(HeapPool, in_heap--);

			if(!cur->ok) DoProcess(cur);
			Setpri(cur->pid, kInf);
			cur->run = 1;
		}

		UNIT_TIME;

		if(cur) {
			if(--cur->tot == 0) {
				cur->run = 0;
				wait(0);

				if(count == n && in_heap == 0) exit(0);
				cur = NULL;
			}
		}
	}
}
