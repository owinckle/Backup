/*
	This is a comment
*/
#include <stdio.h>
int ReturnZero(){
return (0);
}
int main(){
/*
	Yes.
*/
char *data = "/*%c%cThis is a comment%c*/%c#include <stdio.h>%cint ReturnZero(){%creturn (0);%c}%cint main(){%c/*%c%cYes.%c*/%cchar *data = %c%s%c;%cprintf(data, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 34, data, 34, 10, 10, 10);%creturn (ReturnZero());%c}";
printf(data, 10, 9, 10, 10, 10, 10, 10, 10, 10, 10, 9, 10, 10, 34, data, 34, 10, 10, 10);
return (ReturnZero());
}