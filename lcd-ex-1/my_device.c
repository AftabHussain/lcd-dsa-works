/**LCD**/

#include "stdio.h"
#include "device.h"


/*Fn writes on data*/
static int mydev_init(struct packet *p){
        p->size = 0;
        p->data = 0;
	return 1;
}

/*Fn writes on data*/
static void mydev_uninit(struct device_operations *devops){
	devops->devop_init_registered = 0;
}


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

	/* 
         * reg_devops is an environment fn, defined in device.h
         * as a prototype (it is static)
         */
	reg_devops(&devops);
	

}
