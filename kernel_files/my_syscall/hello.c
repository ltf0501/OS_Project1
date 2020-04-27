#include <linux/kernel.h>

asmlinkage void sys_hello(void) {
	printk("Hello World\n");
}
