#include <stdio.h>
char* getMemory04(void);
void test04(void);
int main()
{
    //牛客网某题1
    char* a = "you";
    char b[] = "Welcome you to China!";

    int i,j=0; 
    char *p;
    for(i=0; b[i] != '\0'; i++)
    {
	if(*a == b[i])
	{
	    p = a;
	    for(j = i; *p != '\0'; j++)
	    {
		if(*p != b[j])
		    break;
		p++;
	    }
	    if(*p == '\0')
		break;
	}
    }
    printf("%s", &b[i]);
    //牛客网某题2
    test04();
    return 0;
}

char* getMemory04(void)
{
   char p[] = "hello world";
   return p;
}
void test04(void)
{
   char *str = NULL;
   str = getMemory04();
   printf(str);
}

