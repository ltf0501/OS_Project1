#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/timer.h>

asmlinkage void sys_gettime(struct timespec *r) {
	getnstimeofday(r);
}
