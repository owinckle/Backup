#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int ac,char**av){
int i = 5;
if(i<=0){return 0;}i=*(*av+strlen(av[0])-1)=='y'?i:i-1;(void)ac;char b[200];sprintf(b,"Sully_%d.c",i);FILE*f=fopen(b,"w");char*a="#include<stdio.h>%1$c#include<stdlib.h>%1$c#include<string.h>%1$cint main(int ac,char**av){%1$cint i = %4$d;%1$cif(i<=0){return 0;}i=*(*av+strlen(av[0])-1)=='y'?i:i-1;(void)ac;char b[200];sprintf(b,%2$cSully_%%d.c%2$c,i);FILE*f=fopen(b,%2$cw%2$c);char*a=%2$c%3$s%2$c;fprintf(f,a,10,34,a,i);fclose(f);char b2[200];sprintf(b2,%2$cclang -Wall -Wextra -Werror %%1$s -o Sully_%%2$d%2$c,b,i);system(b2);if(i){sprintf(b2,%2$c./Sully_%%d%2$c,i);system(b2);}}%1$c";fprintf(f,a,10,34,a,i);fclose(f);char b2[200];sprintf(b2,"clang -Wall -Wextra -Werror %1$s -o Sully_%2$d",b,i);system(b2);if(i){sprintf(b2,"./Sully_%d",i);system(b2);}}
