/*
	This is a comment
*/

#include <stdio.h>

int ReturnZero()
{
	return (0);
}

int main()
{
	/* Yes. */
	char *data = "/*%c%cThis is a comment%c*/%c%c#include <stdio.h>%c%cint ReturnZero()%c{%c%creturn (0);%c}%c%cint main()%c{%c%c/* Yes. */%c%cchar *data = %c%s%c;%c%cprintf(data, 10, 9, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 34, data, 34, 10, 9, 10, 9, 10);%c%creturn (ReturnZero());%c}";
	printf(data, 10, 9, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 10, 10, 10, 9, 10, 9, 34, data, 34, 10, 9, 10, 9, 10);
	return (ReturnZero());
}