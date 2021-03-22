#include<linux/init.h>

#include<linux/module.h>

#include<linux/fs.h> //For the character driver support

#include<linux/string.h>

#include<asm/uaccess.h>



 

static char local_buffer[1000];   //driver local buffer

 

static int char_open(struct inode *inod, struct file *pfile);

static ssize_t char_read(struct file *pfile,char *buffer,size_t length,loff_t *off);

static ssize_t char_write(struct file *pfile,const char *buffer,size_t length,loff_t *off);

static int char_release(struct inode *inod,struct file *fil);

//structure containing charice operation

static struct file_operations char_file_operations = {

.read=char_read, //pointer to device read funtion

.write=char_write, //pointer to device write function

.open=char_open,   //pointer to device open function

.release=char_release, //pointer to device realese function

};

 

 

static int char_init(void)   //init function to be called at the time of insmod

{

int t=register_chrdev(240,"Simple Character Device Driver 2",&char_file_operations);
printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);

return 0;
}


static void char_exit(void) //exit function to be called at the time of rmmod

{
printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
unregister_chrdev(240,"Simple Character Device Driver 2");
printk(KERN_ALERT "exit");

}

 

static int char_open(struct inode *inod, struct file *pfile)

{
printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
printk(KERN_ALERT "device opened");

return 0;

}

 

static ssize_t char_read(struct file *pfile,char *buffer,size_t length,loff_t *off)

{
printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
raw_copy_to_user(buffer,local_buffer,length);

return length;

}

 

static ssize_t char_write(struct file *pfile,const char *buffer,size_t length,loff_t *off)

{
printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
raw_copy_to_user(local_buffer,buffer,length);
local_buffer[length]=0;

return length;

}

 

static int char_release(struct inode *inod,struct file *fil)
{
printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);
printk(KERN_ALERT "device closed\n");

return 0;

}

 

module_init(char_init);

module_exit(char_exit);

 
