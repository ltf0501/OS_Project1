#include "heap.h"

int CompareNode(const struct Process *a, const struct Process *b) {
	assert(a && b);

	if(a->tot != b->tot)
		return a->tot < b->tot ? 1 : 0;

	if(a->ready != b->ready)
		return a->ready < b->ready ? 1 : 0;

	return a->id < b->id ? 1 : 0;
}

void Insert(struct Process **pool, int now, struct Process *p) {
	if(now >= kMaxNode) {
		fprintf(stderr, "too many jobs\n");
		exit(1);
	}

	pool[now] = p;
	int a = now;

	while(now > 1) {
		int fa = now >> 1;
		if(CompareNode(pool[now], pool[fa])) {
			struct Process *tmp = pool[now];
			pool[now] = pool[fa];
			pool[fa] = tmp;

			now >>= 1;
		}
		else break;
	}
}

void Delete(struct Process **pool, int now) {
	if(now == 1) {
		pool[1] = NULL;
		return;
	}

	pool[1] = pool[now];
	pool[now] = NULL; 

	int id = 1;
	while(1) {
		if((id << 1) >= now) break;
		int mn = id;
		if((id << 1) < now && CompareNode(pool[id << 1], pool[mn]))
			mn = id << 1;
		if((id << 1 | 1) < now && CompareNode(pool[id << 1 | 1], pool[mn]))
			mn = id << 1 | 1;

		if(mn == id) break;
		else {
			struct Process *tmp = pool[id];
			pool[id] = pool[mn];
			pool[mn] = tmp;
			id = mn;
		} 
	}
}
