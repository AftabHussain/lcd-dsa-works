
struct device {
	char *name;
	char status[10];
	void (*set_device)(char *dev_name, struct device *dev);	
	float id;
	float system_id;
};

struct device_operations {
	int	(*dop_init)(struct device_operations *dev);
	void	(*dop_uninit)(struct device_operations *dev);
	int	(*dop_open)(struct device_operations *dev);
	int	(*dop_stop)(struct device_operations *dev);
	int	devop_init_registered;
};


void reg_device(char *name, struct device *dev);
static int reg_devops(struct device_operations *devops);

