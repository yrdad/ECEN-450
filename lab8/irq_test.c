/*  irq_test.c - Simple character device module
 *  
 *  Demonstrates interrupt driven character device.  Note: Assumption
 *  here is some hardware will strobe a given hard coded IRQ number
 *  (200 in this case).  This hardware is not implemented, hence reads
 *  will block forever, consider this a non-working example.  Could be
 *  tied to some device to make it work as expected.
 *
 *  (Adapted from various example modules including those found in the
 *  Linux Kernel Programming Guide, Linux Device Drivers book and
 *  FSM's device driver tutorial)
 */

/* Moved all prototypes and includes into the headerfile */
#include "irq_test.h"
#include "xparameters.h"
#define MEMSIZE XPAR_IR_DEMOD_0_HIGHADDR - XPAR_IR_DEMOD_0_BASEADDR + 1
#define PHY_ADDR XPAR_IR_DEMOD_0_BASEADDR

/* This structure defines the function pointers to our functions for
   opening, closing, reading and writing the device file.  There are
   lots of other pointers in this structure which we are not using,
   see the whole definition in linux/fs.h */


char* mem;
void* virt_addr;
static int message = 0;
int m_index = 0;
int c_index = 0;
static short int r_index = 0;
static short int w_index = 0;
char* r_queue;
static struct file_operations fops = {
  .read = device_read,
  .write = device_write,
  .open = device_open,
  .release = device_release
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////
//memory functions											//
//////////////////////////////////////////////////////////////////////////////////////////////////////////

void mem_write (int value)
{
	if ((m_index + 1) == 100)
	{
		m_index = 0;
		if (c_index == 0)
		{
			++c_index;
		}
	}
	mem[m_index] = value;
	++m_index;
}

char mem_read()
{
	char temp;
	temp = mem[c_index];
	++c_index;
	if (c_index == 100)
	{
		c_index = 0;
		if (m_index == 0)
		{
			++m_index;
		}
	}
	if (c_index == m_index)
	{
		c_index = 0;
		m_index = 0;
	}
	return temp;
}



/*
 * This function is called when the module is loaded and registers a
 * device for the driver to use.
 */
int my_init(void)
{

  //Virtual Memory Declaration
  virt_addr = ioremap(PHY_ADDR,MEMSIZE);

  init_waitqueue_head(&queue);	/* initialize the wait queue */

  /* Initialize the semaphor we will use to protect against multiple
     users opening the device  */
  sema_init(&sem, 1);

  Major = register_chrdev(0, DEVICE_NAME, &fops);
  if (Major < 0) {		
    printk(KERN_ALERT "Registering char device failed with %d\n", Major);
    iounmap((void*) virt_addr);		//unmap the io in case of device failure.
    return Major;
  }
  printk(KERN_INFO "Registered a device with dynamic Major number of %d\n", Major);
  printk(KERN_INFO "Create a device file for this device with this command:\n'mknod /dev/%s c %d 0'.\n", DEVICE_NAME, Major);

  return 0;		/* success */
}

/*
 * This function is called when the module is unloaded, it releases
 * the device file.
 */
void my_cleanup(void)
{
  /* 
   * Unregister the device 
   */
  unregister_chrdev(Major, DEVICE_NAME);
  iounmap((void*)virt_addr);
}


/* 
 * Called when a process tries to open the device file, like "cat
 * /dev/irq_test".  Link to this function placed in file operations
 * structure for our device file.
 */
static int device_open(struct inode *inode, struct file *file)
{
  printk(KERN_INFO "> starting device_open.\n");
  int irq_ret;
  if (down_interruptible (&sem))
	return -ERESTARTSYS;	
   //Initialize memorymsg = ioread16(virt_addr + 2);
  //mem_write((char) msg);
  //printk(KERN_INFO "attempting malloc...\n");
  //mem = kmalloc(200, GFP_KERNEL);	//16*100 = 1600bits => 200bytes
  //printk(KERN_INFO "malloc complete.\n");
  

  /* We are only allowing one process to hold the device file open at
     a time. */
  if (Device_Open){
    up(&sem);
    return -EBUSY;
  }
  Device_Open++;  
  //wait_event_interruptible(queue, (msg_Ptr != NULL));
   /* OK we are now past the critical section, we can release the
     semaphore and all will be well */
  up(&sem);
  printk(KERN_INFO "> passed the critical section.\n");
  r_queue = kmalloc(200, GFP_KERNEL);
  /* request a fast IRQ and set handler */
  irq_ret = request_irq(IRQ_NUM, irq_handler, 0 /*flags*/ , DEVICE_NAME, NULL);
  if (irq_ret < 0) {		/* handle errors */
    printk(KERN_ALERT "Registering IRQ failed with %d\n", irq_ret);
    return irq_ret;
  }

  try_module_get(THIS_MODULE);	/* increment the module use count
				   (make sure this is accurate or you
				   won't be able to remove the module
				   later. */
  printk(KERN_INFO "end of 'device_open'\n");
  return 0;
}

/* 
 * Called when a process closes the device file.
 */
static int device_release(struct inode *inode, struct file *file)
{
  Device_Open--;		/* We're now ready for our next caller */
  kfree(mem);
  free_irq(IRQ_NUM, NULL);
  
  /* 
   * Decrement the usage count, or else once you opened the file,
   * you'll never get get rid of the module.
   */
  module_put(THIS_MODULE);
  
  return 0;
}

/* 
 * Called when a process, which already opened the dev file, attempts to
 * read from it.
 */
static ssize_t device_read(struct file *filp,	/* see include/linux/fs.h   */
			   char *buffer,	/* buffer to fill with data */
			   size_t length,	/* length of the buffer     */
			   loff_t * offset)
{
  printk(KERN_INFO "reading from device\n");
  int bytes_read = 0;
  int result;

  while(length > 0) {
	result = put_user(r_queue[r_index*2], buffer++);
	result = put_user(r_queue[r_index*2 + 1],buffer++);
	if (result < 0){
		printk(KERN_ALERT "read error\n");
		break;
	}
	
	length = length - 2;
	r_index++;
	if(r_index == w_index){
		r_index = 0;
		w_index = 0;
		if(length > 0)
			return bytes_read;
	}
  }
  
  /* 
   * Most read functions return the number of bytes put into the buffer
   */

  printk(KERN_INFO "end of 'device_read'\n");
  return bytes_read;
}

/*  
 * Called when a process writes to dev file: echo "hi" > /dev/hello 
 * Next time we'll make this one do something interesting.
 */
static ssize_t
device_write(struct file *filp, const char *buff, size_t len, loff_t * off)
{

  /* not allowing writes for now, just printing a message in the
     kernel logs. */
  printk(KERN_ALERT "Sorry, this operation isn't supported.\n");
  return -EINVAL;		/* Fail */
}

irqreturn_t irq_handler(int irq, void *dev_id) {
  r_queue[w_index*2] = ioread8(virt_addr+2);
  r_queue[w_index*2 + 1] = ioread8(virt_addr+3);
  if(w_index < 99)
	++w_index;
  iowrite16(0x01,virt_addr+10);
  return IRQ_HANDLED;
}



/* These define info that can be displayed by modinfo */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Paul V. Gratz (and others)");
MODULE_DESCRIPTION("Module which creates a character device and allows user interaction with it");

/* Here we define which functions we want to use for initialization
   and cleanup */
module_init(my_init);
module_exit(my_cleanup);
