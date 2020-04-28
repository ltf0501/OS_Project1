#include "RR.h"

void RR_Scheduler(struct Process *process, int n) {
	int count = 0, round = 500;
	struct Node *head = NULL, *tail = NULL;

	for(int time = 0; ; time++) {
		while(count < n && process[count].ready <= time) {
			DoProcess(&process[count]);
			struct Node *now = (struct Node *)calloc(1, sizeof(struct Node));
			now->p = &process[count++];

			if(!head) head = tail = now;
			else {
				tail->next = now;
				tail = now;
			}
		}

		if(round == 0) {
			Setpri(head->p->pid, 1);
			head->p->run = 0;
			round = 500;

			if(head->next) {
				struct Node *now = head;
				head = head->next;
				now->next = NULL;
				tail->next = now;
				tail = now;
			}
		}

		if(head && !head->p->run) {
			Setpri(head->p->pid, kInf);
			head->p->run = 1;
		}

		UNIT_TIME;

		if(head) {
			round--;
			if(--head->p->tot == 0) {
				head->p->run = 0;
				wait(0);
				round = 500;

				struct Node *now = head;
				if(head->next) head = head->next;
				else head = tail = NULL;

				free(now);

				if(!head && count == n) exit(0);
			}
		} 
	}
}
