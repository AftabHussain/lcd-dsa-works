/**PART OF LCD**/

#include "stdio.h"
#include "device.h"

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
}
