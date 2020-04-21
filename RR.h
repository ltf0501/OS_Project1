#ifndef RR_H_
#define RR_H_

#include "util.h"

struct Node {
	struct Process *p;
	struct Node *next;
};

void RR_Scheduler(struct Process *process, int n);

#endif // RR_H_
