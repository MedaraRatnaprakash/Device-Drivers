#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>

//M.RATNAPRAKASH
//CED17I032

 

char *string;

int integer=0;

 

module_param(integer, int, 0);

module_param(string, charp, S_IRUGO);


static int hello_init(void) //init function to be called at the time of insmod

{

printk(KERN_ALERT "init function called\n"); //kernel print
printk(KERN_ALERT "value of str is= %d\n",integer); //kernel print to print value of integer

return 0;

}

 

static void hello_exit(void) //exit function to be called at the time of rmmod

{

printk(KERN_ALERT "exit function called"); //kernel print

}

 

module_init(hello_init);

module_exit(hello_exit);
