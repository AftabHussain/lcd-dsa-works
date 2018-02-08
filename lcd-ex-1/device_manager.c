/**ENVIRONMENT (simulates the kernel)**/

#include "device.h"
#include "string.h"

/* 
 * Environment Data
 */
typedef struct device_manager {
	char *log [10];
	int dev_req_count;
	int dev_reg_count;
} device_manager;

device_manager dm;

/*
 * Invoked by the LCD
 * It updates both Environment and LCD data
 */
void reg_device(char *name, struct device *dev){

	//read/write LCD data (cross-domain)
	dev->name = name;
	
	//write Env data (intra-domain)
	dm.log[dm.dev_req_count] = name;	

	//read/write LCD data (cross-domain)
	strcpy(dev->status,"ready");

	//write Env data (intra-domain)
	dm.dev_req_count++;

	//read/write LCD data (cross-domain)
	dev->system_id = (dev->id * dm.dev_req_count)/1234;

}

/*
 * Also invoked by the LCD.
 * It calls LCD functions via the *devops struct function
 * pointers which updates the LCD data.
 * It also updates Environment data dev_reg_count	
 */
static int reg_devops(struct device_operations *devops){
	
        struct packet p; 
	dm.dev_reg_count++;
	devops->devop_init_registered = 1;
	devops->dop_init(&p);
	
	return 1;
};
