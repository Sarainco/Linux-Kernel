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

static void hello_dev_release(struct device *dev)
{

}

static struct platform_device hello_dev = {
    .name = "100ask_hello",
    .dev = {
        .release = hello_dev_release,
    },
};

static int __init hello_dev_init(void)
{
    int ret;
    ret = platform_device_register(&hello_dev);
    return ret;
}

static void __exit hello_dev_exit(void)
{
    int ret;
    ret = platform_device_unregister(&hello_dev);
}

module_init(hello_dev_init);
module_exit(hello_dev_exit);

MODULE_LICENSE("GPL");