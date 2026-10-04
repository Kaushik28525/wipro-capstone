#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "resource_monitor"
#define CLASS_NAME  "resource_class"

static dev_t device_number;
static struct cdev resource_cdev;
static struct class *resource_class;
static struct device *resource_device;

static char driver_message[256] =
    "Linux Resource Monitor Driver is working!\n";

static int resource_open(struct inode *inode, struct file *file)
{
    pr_info("resource_monitor: device opened\n");
    return 0;
}

static int resource_release(struct inode *inode, struct file *file)
{
    pr_info("resource_monitor: device closed\n");
    return 0;
}

static ssize_t resource_read(
    struct file *file,
    char __user *buffer,
    size_t length,
    loff_t *offset)
{
    size_t message_length;

    if (*offset > 0)
        return 0;

    message_length = strlen(driver_message);

    if (length < message_length)
        return -EINVAL;

    if (copy_to_user(buffer, driver_message, message_length))
        return -EFAULT;

    *offset = message_length;

    return message_length;
}

static ssize_t resource_write(
    struct file *file,
    const char __user *buffer,
    size_t length,
    loff_t *offset)
{
    size_t copy_length;

    copy_length = min(length, sizeof(driver_message) - 1);

    if (copy_from_user(driver_message, buffer, copy_length))
        return -EFAULT;

    driver_message[copy_length] = '\0';

    pr_info("resource_monitor: message received from user\n");

    return copy_length;
}

static const struct file_operations resource_fops = {
    .owner = THIS_MODULE,
    .open = resource_open,
    .read = resource_read,
    .write = resource_write,
    .release = resource_release,
};

static int __init resource_driver_init(void)
{
    int result;

    result = alloc_chrdev_region(
        &device_number,
        0,
        1,
        DEVICE_NAME
    );

    if (result < 0) {
        pr_err("resource_monitor: failed to allocate device number\n");
        return result;
    }

    cdev_init(&resource_cdev, &resource_fops);

    result = cdev_add(
        &resource_cdev,
        device_number,
        1
    );

    if (result < 0) {
        pr_err("resource_monitor: failed to add cdev\n");
        unregister_chrdev_region(device_number, 1);
        return result;
    }

    resource_class = class_create(CLASS_NAME);

    if (IS_ERR(resource_class)) {
        pr_err("resource_monitor: failed to create class\n");
        cdev_del(&resource_cdev);
        unregister_chrdev_region(device_number, 1);
        return PTR_ERR(resource_class);
    }

    resource_device = device_create(
        resource_class,
        NULL,
        device_number,
        NULL,
        DEVICE_NAME
    );

    if (IS_ERR(resource_device)) {
        pr_err("resource_monitor: failed to create device\n");
        class_destroy(resource_class);
        cdev_del(&resource_cdev);
        unregister_chrdev_region(device_number, 1);
        return PTR_ERR(resource_device);
    }

    pr_info("resource_monitor: driver loaded successfully\n");
    pr_info("resource_monitor: major=%d minor=%d\n",
            MAJOR(device_number),
            MINOR(device_number));

    return 0;
}

static void __exit resource_driver_exit(void)
{
    device_destroy(
        resource_class,
        device_number
    );

    class_destroy(resource_class);

    cdev_del(&resource_cdev);

    unregister_chrdev_region(
        device_number,
        1
    );

    pr_info("resource_monitor: driver unloaded\n");
}

module_init(resource_driver_init);
module_exit(resource_driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kaushik Anand");
MODULE_DESCRIPTION(
    "Linux Character Device Driver for System Resource Monitor"
);
MODULE_VERSION("1.0");
