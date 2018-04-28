#include <unistd.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int i = 5;
	int s = 6 + log10(i + 1) + 1;
	char *file = malloc(s * sizeof(char));
	sprintf(file, "Sully_%d%s", i + 1, ".c");
	if (access(file, F_OK) != -1)
		i -= 1;
	s = 6 + log10(i);
	free(file);
	file = malloc(s * sizeof(char));
	sprintf(file, "Sully_%d%s", i, ".c");
	if (access(file, F_OK) != -1)
		i -= 1;
	s = 6 + log10(i);
	free(file);
	file = malloc(s * sizeof(char));
	sprintf(file, "Sully_%d%s", i, ".c");
	char *data = "#include <unistd.h>%c#include <math.h>%c#include <stdio.h>%c#include <stdlib.h>%c#include <fcntl.h>%c%cint main(void)%c{%c%cint i = 5;%c%cint s = 6 + log10(i + 1) + 1;%c%cchar *file = malloc(s * sizeof(char));%c%csprintf(file, %cSully_%%d%%s%c, i + 1, %c.c%c);%c%cif (access(file, F_OK) != -1)%c%c%ci -= 1;%c%cs = 6 + log10(i);%c%cfree(file);%c%cfile = malloc(s * sizeof(char));%c%csprintf(file, %cSully_%%d%%s%c, i, %c.c%c);%c%cif (access(file, F_OK) != -1)%c%c%ci -= 1;%c%cs = 6 + log10(i);%c%cfree(file);%c%cfile = malloc(s * sizeof(char));%c%csprintf(file, %cSully_%%d%%s%c, i, %c.c%c);%c%cchar *data = %c%s%c;%c%cint fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);%c%cif (fd)%c%c{%c%c%cDPRINTF%c%c}%c%creturn (0);%c}";
	int fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd)
	{
		dprintf(fd, data, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10, 9, 10, 9, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10, 9, 10, 9, 34, 34, 34, 34, 10, 9, 34, data, 34, 10, 9, 10, 9, 10, 9, 10, 9, 9, 10, 9, 10, 9, 10);
	}
	return (0);
}