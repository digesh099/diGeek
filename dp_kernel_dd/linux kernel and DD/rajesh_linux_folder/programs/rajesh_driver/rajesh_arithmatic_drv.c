#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/sched.h>
#include <linux/errno.h>
#include <asm/current.h>
#include <linux/device.h>
#include<linux/slab.h>
#include "ioctl_const.h"

#define CHAR_DEV_NAME "veda_cdrv"
#define MAX_LENGTH length



static char *char_device_buf;
struct cdev *veda_cdev;
static unsigned int length = 4000;
dev_t mydev;
int count=1;
static struct class *veda_class;


static int char_dev_open(struct inode *inode,
                            struct file  *file)
{
	return 0; 

}

static int char_dev_release(struct inode *inode,
                            struct file *file)
{
        return 0;
}

static ssize_t rajesh_dev_read(struct file *file, char *buf,size_t lbuf,loff_t *ppos)
{

	printk("read function called succesfully\n");
}

static ssize_t rajesh_dev_write(struct file *file, char *buf,size_t lbuf,loff_t *ppos)
{

	printk("write function called succesfully\n");
}
static int rajesh_dev_ioctl(struct file *file, char *buf, unsigned int cmd, unsigned long arg)
{
	switch( cmd )
	{
		case add : 
			   retbytes = copy_from_user(&value,(unsigned int*)arg,sizeof(unsigned int));
			   printk("the value was copied from the user space ");
			   break;
		case sub : 
			   retbytes = copy_from_user(&value,(unsigned int*)arg,sizeof(unsigned int));
			   printk("the value was copied from the user space ");
			   break;
		case mul :
			   retbytes = copy_from_user(&value,(unsigned int*)arg,sizeof(unsigned int));
			   printk("the value was copied from the user space ");
			   break;
		case div :
			   retbytes = copy_from_user(&value,(unsigned int*)arg,sizeof(unsigned int));
			   printk("the value was copied from the user space ");
			   break;

		default :
			   printk("no user command match\n");
	}
	
	return 0;
}

static struct file_operations rajesh_fops = {
        .read = gpio_read,
        .write = gpio_write,
        .ioctl = gpio_ioctl,
        .open = gpio_open,
        .release = gpio_release,
};
static __init int char_dev_init(void)
{
        int ret;

        if (alloc_chrdev_region (&mydev, 0, count, CHAR_DEV_NAME) < 0) {
            printk (KERN_ERR "failed to reserve major/minor range\n");
            return -1;
    }

        if (!(veda_cdev = cdev_alloc ())) {
            printk (KERN_ERR "cdev_alloc() failed\n");
            unregister_chrdev_region (mydev, count);
            return -1;
        }
        cdev_init(veda_cdev,&char_dev_fops);

        ret=cdev_add(veda_cdev,mydev,count);
        if( ret < 0 ) {
                printk(KERN_INFO "Error registering device driver\n");
                cdev_del (veda_cdev);
                unregister_chrdev_region (mydev, count);
                return -1;
        }
static __exit void  char_dev_exit(void)
{
         device_destroy (veda_class, mydev);
         class_destroy (veda_class);
         cdev_del(veda_cdev);
         unregister_chrdev_region(mydev,1);
         printk(KERN_INFO "\n Driver unregistered \n");
}
module_init(char_dev_init);
module_exit(char_dev_exit);



















