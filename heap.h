#ifndef HEAP_H_
#define HEAP_H_

#define kMaxNode 101 

#include "util.h"

int CompareNode(const struct Process *a, const struct Process *b); 

void Insert(struct Process **pool, int now, struct Process *p);
void Delete(struct Process **pool, int now);
#endif // HEAP_H_
