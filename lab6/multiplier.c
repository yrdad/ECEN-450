// multiplier.c - Character device module for multiplication module

#include <linux/module.h> //needed by all modules
#include <linux/kernel.h> //needed for KERN_* and printk
#include <linux/init.h>   //needed for __init and __exit
#include <asm/io.h>	  //needed for IO read/write
#include <linux/moduleparam.h>//needed for module parameters
#include <linux/fs.h>	  //file ops
#include <linux/sched.h>  //access to "current" processes structure
#include <asm/uaccess.h>  //utilites for userspace
#include "xparameters.h"  //physical multipler address
#include <linux/slab.h>


#define PHY_ADDR XPAR_MULTIPLY_0_BASEADDR
#define MEMSIZE XPAR_MULTIPLY_0_HIGHADDR - XPAR_MULTIPLY_0_BASEADDR + 1
#define DEVICE_NAME "multiplier"

static int Device_Open = 0; /* Flag to signify open device */

static int device_open(struct inode*, struct file*);
static int device_release(struct inode*, struct file*);
static ssize_t device_read(struct file*, char* ,size_t, loff_t*);
static ssize_t device_write(struct file*, const char*, size_t, loff_t*);

void* virt_addr;
static int Major;

/*--------------------------------------------------------------------*/
/* Implementation */
/*--------------------------------------------------------------------*/

/* This structure defines the function pointers to our function for
   opening, closing, reading, and writing the device file. There are
   lots of other pointers in this strucutre which we are not using,
   see the whole definition in linux/fs.h */
static struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};


/* This function is called when the module is loaded and
   registers a device for th driver to use */
static int __init my_init(void) {

	/* map virtual address to multiplier physical address */
	// use ioremap
	virt_addr = ioremap(PHY_ADDR, MEMSIZE);
	printk(KERN_INFO "Physical Address: %x", PHY_ADDR);
	printk(KERN_INFO "Virtual  Address: %x", virt_addr);

	/* This function call registers a device and returns a
	  major number associated with it. Be wary, the device
	   file could be accessed as soon as you register it, make
	   sure anything you need (i.e. buffers etc.) are setup
	   _BEFORE_ you register the device */
	Major = register_chrdev(0,DEVICE_NAME, &fops);

	/* Negative values indicate a problem */
	if (Major < 0) {
	    /* Make sure you release and other resources
	       you've already grabbed if you get here so you
	       don't leave the kernel in a broken state. */
	    printk(KERN_ALERT "Registering char device failed with %d\n", Major);
	    return Major;
	}

	printk(KERN_INFO "Registered a device with dynamic Major number of %d\n", Major);

	printk(KERN_INFO "Create a device file for this device with command:\n'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, Major);

	return 0; // success
}


/* This function is called when the module is unloaded, it
   releases the device file */
static void __exit my_exit(void){
	/* Unregister the device */
	unregister_chrdev(Major, DEVICE_NAME);

	/* free memory */
	iounmap((void*)virt_addr);
}

/* Called when a process tries to open the device file, like
   "cat/dev/multiplier". Link to this function placed in file
   operations structure for our device file. */
static int device_open(struct inode *inode, struct file *file){

	/* In this case we are only allowing one process to hold
	   the device file open at a time */
	if (Device_Open)	/* Device_Open is the flag for the
				   usage of the device file */
		return -EBUSY;  /* Failure to open device is given
				   back to userland program. */
	Device_Open++;		/* Keeps count of device opens */

	/* Create a string to output when the device is opened. This
	   string is given to the user program in device_read. Note:
	   we are using the "current" task structure which contains
	   information about the process that opened the device file */

	try_module_get(THIS_MODULE); /* Incriment the module use count
					(make sure this is accurate or
					you won't be able to remove
					the module later */

	return 0;
}


/* Called when a process closes the device file */
static int device_release(struct inode *inode, struct file *file){
	Device_Open--;		/* We're now ready for our next caller */

	/* Decrement the usage count, or else once you opened the file,
	   you'll never get rid of the module. */
	module_put(THIS_MODULE);

	return 0;
}


/* Called when a process, which already opened the dev file, attempts
   to read from it */
static ssize_t device_read(struct file *filep, 	/* see include/linux/fs.h */
			   char* buffer,	/* buffer to fill with data */
			   size_t length,	/* length of the buffer */
			   loff_t* offset)
{
	/* Number of bytes actually written to the buffer */
	int bytes_read = 0;

	/* Buffer protections: integer size is 4 bytes. Since our
	   hardware has support for 3 integer registers, the total
 	   buffer memory size should range from 0*4 -to-  (3 registers) *(4 bytes) */
	if (length < 0 || length > 12) {
		printk(KERN_INFO "Invalid buffer length\n");
		return -1;
	}
	/* The buffer is in the user data segment, not the kernel segment
		 so "*" assignment won't work. We ahve to use put_user which
		 copies data from the kernel data segment to the user data segment */
	int i;
	for(i=0;i<length;i++){
		put_user(ioread8(virt_addr+i), buffer+i);
		bytes_read++;
	}

	/* Most read functions return the number of bytes put into the buffer */
	return bytes_read;
}


/* Called when a process writes to dev file */
static ssize_t device_write(struct file *filp, const char* buffer, size_t length, loff_t* offset){


	char* char_buf = (char*)kmalloc(length*sizeof(char),GFP_KERNEL);

	int i;
	for(i=0; i<length; i++)
		get_user(char_buf[i],buffer+i);

	int* buf = (int*)char_buf;

	iowrite32(buf[0], virt_addr+0);
	iowrite32(buf[1], virt_addr+4);

	kfree(char_buf);

	return i;
}




/* These define info that can be displatyed by modinfo */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kyle Loyka");
MODULE_DESCRIPTION("Module which creates a character device and allows user interaction with it");

/* Here we define which functions we want to use for initialization
   and cleanup */
module_init(my_init);
module_exit(my_exit);
