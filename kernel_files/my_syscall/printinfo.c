#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/timer.h>

asmlinkage void sys_printinfo(int pid, long a, long b, long c, long d) {
	printk(KERN_INFO "[Project1] %d %ld.%09ld %ld.%09ld\n", pid, a, b, c, d);
}
