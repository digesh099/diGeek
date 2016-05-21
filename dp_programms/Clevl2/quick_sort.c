#include<stdio.h>
int split(int*,int,int);
void quick_sort(int*,int,int);
main()
{
	int a[10]={8,13,26,6,3,15,32,1,5,18};
	int low=0,high=9,i;
	quick_sort(a,low,high);
	printf("sorted array");
	for(i=0;i<10;i++)
	{
		printf("%d\n",a[i]);
	}
}
void quick_sort(int *a,int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=split(a,low,high);
		quick_sort(a,low,mid-1);
		quick_sort(a,mid+1,high);
	}
}
	int split(int *a,int low,int high)
	{
		int pivot,p,q,temp;
		pivot=a[low];
		p=low+1;
		q=high;
		while(q>p)
		{
			while(a[p]<pivot)
			{
				p++;
			}
			while(a[q]>pivot)
			{
				q--;
			}
			if(q>=p)
			{
				temp=a[p];
				a[p]=a[q];
				a[q]=temp;
			}
		}
		temp=a[low];
		a[low]=a[q];
		a[q]=temp;
		return q;
	}
	
