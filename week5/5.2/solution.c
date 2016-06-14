#include "stdlib.h"
#include "fcntl.h"
#include "sys/select.h"
#include "stdio.h"

int main(int argc, char const *argv[])
{
  int fileDescriptor1 = open("./in1", O_RDONLY);
  int fileDescriptor2 = open("./in2", O_RDONLY);
  int sum; 
  for (;;)
  {
    fd_set fds;
    int maxfd;
    int res;
    char buf[256];

    FD_ZERO(&fds); // Clear FD set for select
    FD_SET(fileDescriptor1, &fds);
    FD_SET(fileDescriptor2, &fds);

    maxfd = fileDescriptor1 > fileDescriptor2 ? fileDescriptor1 : fileDescriptor2;

    select(maxfd + 1, &fds, NULL, NULL, NULL);

    if (fcntl(fileDescriptor1, F_GETFD) <= 0 && fcntl(fileDescriptor2, F_GETFD) <= 0)
    {
      printf("%d\n", sum);
      exit(0);
    }
    if (FD_ISSET(fileDescriptor1, &fds))
    {
       // We can read from fileDescriptor1
       res = read(fileDescriptor1, buf, sizeof(buf));
       if (res > 0)
       {
        sum += atoi(buf);
       }
    }
    if (FD_ISSET(fileDescriptor2, &fds))
    {
       // We can read from fileDescriptor2
      res = read(fileDescriptor2, buf, sizeof(buf));
      if (res > 0)
      {
        sum += atoi(buf);
      }
    }
  }
  return 0;
}