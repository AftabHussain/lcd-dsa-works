/**PART OF ENVIRONMENT**/

#include "device.h"
#include "string.h"

/* 
 * Environment Data
 */
typedef struct device_manager {
	char log [10][10];
	int dev_count;
} device_manager;

device_manager dm;

/*
 * Invoked by the LCD
 * It updates both Environment and LCD data
 */
void reg_device(char *name, struct device *dev){

	//write LCD data (cross-domain)
	dev->name = name;
	
	//write LCD data (cross-domain)
	strcpy(dev->status,"ready");

	//write Env data (intra-domain)
	dm.dev_count++;

	//read/write LCD data (cross-domain)
	dev->system_id = (dev->id * dm.dev_count)/1234;

}
