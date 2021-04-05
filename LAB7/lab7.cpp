
#include <iostream>
#include <fcntl.h>
 
using namespace std;


int main()
{
char memory[] = "/dev/mem";
int fptr;
fptr = open(memory, O_RDWR);

if (fptr < 0)
{
cerr << "Error: " << error_t(errno)<<endl;
exit(1);
}

else
{
printf("Sucessfully opened");
}


FILE *file;

file = fopen("/var/log/syslog", "w");

if (file == NULL)
{
cerr << "Error: " << error_t(errno)<<endl;
exit(1);
}
else
{
   printf("Opened Sucessfully\n");
}
   return 0;
}
