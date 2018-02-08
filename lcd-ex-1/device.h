#if !defined(__DEVICE_H__)
#define __DEVICE_H__ 

struct packet {
   int size;
   char *data;
};

struct device {
	char *name;
	char status[10];
	void (*set_device)(char *dev_name, struct device *dev);	
	float id;
	float system_id;
};

struct device_operations {
	
	/*FP arg is a struct var of struct packet*/
	int	(*dop_init)(struct packet *p);

	/*FP arg is a struct var of FP's parent struct*/
	void	(*dop_uninit)(struct device_operations *dev);

	int	(*dop_open)(struct device_operations *dev);
	int	(*dop_stop)(struct device_operations *dev);
	int	devop_init_registered;
};


void reg_device(char *name, struct device *dev);
static int reg_devops(struct device_operations *devops);

#endif
