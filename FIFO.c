#include "FIFO.h"

void FIFO_Scheduler(struct Process *process, int n) {
	if(!n) exit(0);
	int cur = 0, count = 0;

	for(int time = 0; ; time++) {
		while(count < n && process[count].ready <= time) {
			DoProcess(&process[count++]);
		}
		if(process[cur].ok && !process[cur].run) {
			Setpri(process[cur].pid, kInf);
			process[cur].run = 1;
		}

		UNIT_TIME;

		if(process[cur].run) {
			if(--process[cur].tot == 0) {
				process[cur].run = 0;
				wait(0);

				if(++cur == n) exit(0);
			}
		} 
	} 
}
