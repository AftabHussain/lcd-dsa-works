/**PART OF LCD**/

#include "stdio.h"
#include "device.h"


static int mydev_init(struct device_operations *devops){}

static void mydev_uninit(struct device_operations *devops){}


int main() {
	
        /* 
         * struct device (LCD Data) is defined in device.h
         */	
	struct device my_printer;

        /* 
         * reg_device is an environment fn, defined in device.h
         * as a prototype
         */
        my_printer.set_device = reg_device;

	/*
	 * An invocation to the environment from the LCD
	 */
	my_printer.set_device("PRINTER", &my_printer);


	/*
	 * initializing some fields of devops struct
	 */
	static struct device_operations devops = {
		.dop_init	= mydev_init,
		.dop_uninit	= mydev_uninit,
	};
	
	reg_devops(&devops);
	

}
