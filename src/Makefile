obj-m := test_rbtree_string.o
test_rbtree_string-objs := test_rbtree_string_module.o rbtree/data_structure.o rbtree/rbtree_api.o common/time_calculating.o common/utilities.o
ccflags-y := -std=gnu99 -Wno-declaration-after-statement
KERNEL_DIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	rm -rf **/*.o **/*~ core **/*.depend **/.*.cmd **/*.ko **/*.mod.c **/*.tmp_versions **/*.dwo **/*.mod **/*.order **/Module.symvers **/*.o.d
	rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions *.dwo *.mod *.order Module.symvers *.o.d