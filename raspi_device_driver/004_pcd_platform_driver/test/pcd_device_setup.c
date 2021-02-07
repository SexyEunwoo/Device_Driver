/*

1. Create 2 platform devices
2. platform device must have a deivce private data
3. platform device must declear release function in dev->release

*/

#include <linux/module.h>
#include <linux/platform_device.h>
#include "platform.h"

#undef pr_fmt
#define pr_fmt(fmt) "%s : " fmt, __func__

void pcd_dev_release(struct device* dev);

struct pcd_platform_data pcd_pdata[3] = {
	[0] = {
		.size = 1024,
		.perm = RDWR,
		.serial_number = "PCD1"
	},
	[1] = {
		.size = 512,
		.perm = RDONLY,
		.serial_number = "PCD2"
	},
	[2] = {
		.size = 512,
		.perm = WRONLY,
		.serial_number = "PCD3"
	}
};

struct platform_device pcd_platform_device_1 = {
	.name = "pcd_dev",
	.id = 0,
	.dev = { .platform_data = &pcd_pdata[0], .release = pcd_dev_release }
};
struct platform_device pcd_platform_device_2 = {
	.name = "pcd_dev",
	.id = 1,
	.dev = { .platform_data = &pcd_pdata[1], .release = pcd_dev_release }
};
struct platform_device pcd_platform_device_3 = {
	.name = "pcd_dev",
	.id = 2,
	.dev = { .platform_data = &pcd_pdata[2], .release = pcd_dev_release }
};

static int __init pcd_platform_init(void)
{
	platform_device_register(&pcd_platform_device_1);
	platform_device_register(&pcd_platform_device_2);
	platform_device_register(&pcd_platform_device_3);

	pr_info("module inserted \n");
	return 0;
}

static void __exit pcd_platform_cleanup(void)
{
	platform_device_unregister(&pcd_platform_device_1);
	platform_device_unregister(&pcd_platform_device_2);
	platform_device_unregister(&pcd_platform_device_3);

	pr_info("module removed \n");
}

void pcd_dev_release(struct device* dev)
{
	pr_info("pcd_dev_release function \n");
}

module_init(pcd_platform_init);
module_exit(pcd_platform_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EUNWOO");
MODULE_DESCRIPTION("pcd_dev_setup");

