/*This is a comment*/
#include <stdio.h>
int ReturnZero(){
return (0);
}
int main(){
/* Yes. */
char *data = "/*This is a comment*/%c#include <stdio.h>%cint ReturnZero(){%creturn (0);%c}%cint main(){%c/* Yes. */%cchar *data = %c%s%c;%cprintf(data, 10, 10, 10, 10, 10, 10, 10, 34, data, 34, 10, 10, 10);%creturn (ReturnZero());%c}";
printf(data, 10, 10, 10, 10, 10, 10, 10, 34, data, 34, 10, 10, 10);
return (ReturnZero());
}