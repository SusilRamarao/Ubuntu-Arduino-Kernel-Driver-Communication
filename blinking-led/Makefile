all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

obj-m := arduino_comm_driver.o

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
