/*
	Grace had a kid...
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define FILE "Grace_kid.c"
#define DATA "/*%c%cGrace had a kid...%c*/%c%c#include <stdio.h>%c#include <unistd.h>%c#include <fcntl.h>%c%c#define FILE %cGrace_kid.c%c%c#define DATA %c%s%c%c#define GRACE() int main(){int fd = open(FILE, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);if (fd){dprintf(fd, DATA, 10, 9, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 34, DATA, 34, 10, 10, 10);close(fd);}return (0);}%c%cGRACE()"
#define GRACE() int main(){int fd = open(FILE, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);if (fd){dprintf(fd, DATA, 10, 9, 10, 10, 10, 10, 10, 10, 10, 34, 34, 10, 34, DATA, 34, 10, 10, 10);close(fd);}return (0);}

GRACE()