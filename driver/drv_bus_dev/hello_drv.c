#include <linux/module.h>

#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/miscdevice.h>
#include <linux/kernel.h>
#include <linux/major.h>
#include <linux/mutex.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/stat.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/tty.h>
#include <linux/kmod.h>
#include <linux/gfp.h>
#include <linux/platform_device.h>

static int hello_drv_probe(struct platform_device *pdev)
{
    return 0;
}

static int hello_drv_remove(struct platform_device *pdev)
{
    return 0;
}

static struct platform_driver hello_drv = {
    .probe = hello_drv_probe,
    .remove = hello_drv_remove,
    .driver = {
        .name = "100ask_hello",
    },
};

static int __init hello_drv_init(void)
{
    int ret;
    ret = platform_driver_register(&hello_drv);
    return ret;
}

static void __exit hello_drv_exit(void)
{
    int ret;
    ret = platform_driver_unregister(&hello_drv);
}

module_init(hello_drv_init);
module_exit(hello_drv_exit);

MODULE_LICENSE("GPL");