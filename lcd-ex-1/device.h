#include "stdlib.h"

struct device {
	char *name;
	char status[10];
	void (*set_device)(char *dev_name, struct device *dev);	
	float id;
	float system_id;
};


void reg_device(char *name, struct device * dev);


