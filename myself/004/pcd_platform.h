#define RDONLY	0x01
#define WRONLY	0x10
#define RDWR	0x11
#define NUM_OF_DEV	4

struct pcd_driver_private_data
{
<<<<<<< HEAD
	dev_t dev_num_base;
	int dev_num;
=======
	dev_t dev_num;
>>>>>>> 32ea72da566c3ef9bce1b71d94ff28d8ccdae91a
	struct class* pcd_class;
	struct device* pcd_device;
};

struct pcd_device_private_data
{
	dev_t dev_num;
	char* buf;
	int buf_size;
	int perm;
	const char* serial_num;
	struct cdev cdev;
};

struct pcd_platform_data
{
	int buf_size;
	int perm;
	const char* serial_num;
};