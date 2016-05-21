#include<stdio.h>
#include<string.h>

#define n 5
#define len 10

int main(void)
{
	char arr[n][len] = {
				"white",
				"red",
				"green",
				"yellow",
				"blue"
			   };
	char temp[10];
	int i, j;
	printf("before sorting :\n");
	for(i = 0; i < n; i++)
	printf("%s    ",arr[i]);
	printf("\n");
	for(i = 0; i < n; i++)
	  for(j = i + 1; j < n; j++)	
	  if(strcmp(arr[i],arr[j]) > 0)		
	   {
		strcpy(temp, arr[i]);
		strcpy(arr[i],arr[j]);
		strcpy(arr[j],temp);
	   }
	printf("after sorting  :\n");
	for(i = 0; i < n; i++)
		printf("%s    ",arr[i]);
		printf("\n");
		return 0;
}
