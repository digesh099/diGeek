/* this progaram creates the manually developed strlen function
   this program finds the length of the any given string */

#include<stdio.h>
#include<stdlib.h>

unsigned int strlen_str(char str[]);

int main(void)
{
	char str[50];
	int x;
	printf("enter the string to find the length\n");
	gets(str);

// function calling

	x = strlen_str(str);
	printf("the length of the given string = %d\n",x);
}

// string length implementation 

unsigned int strlen_str(char strng[])
{
	int i = 0;
	while(strng[i] != '\0')
	i++;
	return i;
}


