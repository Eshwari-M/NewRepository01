#include <stdio.h>
#include <stdlib.h>
int *a;
int max,top=-1;
void push(int ele)
{
	if(top==max-1)
	{
		max=2*max;
		printf("Stack overflow so reallocated and pushed");
		a=realloc(a,max*sizeof(int));
	}
    a[++top]=ele;
}
int pop()
{
	if(top==-1)
	{
		printf("Stack underflow");
		return -999;
	}
	else
	{
		return a[top--];
	}
}
void display()
{
  int i;
  	if(top==-1)
		printf("Stack empty");
	else
	{
	printf("Stack elements are=");
	for(i=top;i>=0;i--)
	printf("%d\t",a[i]);
}
}
int main()
{
	int ele,choice;
	printf("Enter max=");
	scanf("%d",&max);
	a=(int *)malloc(max*sizeof(int));
	while(1)
	{
		printf("\n Enter choice:");
		printf("\n 1 for insert\n 2 for delete \n 3 for display \n 4 for exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter ele to be pushed=");
			       scanf("%d",&ele);
			       push(ele);
			       break;
			case 2:ele=pop();
			       if(ele!=-999)
			       printf("Deleted ele=%d",ele);
			break;
			case 3: display();
			break;
			case 4:free(a);
			exit(0);
			default:printf("Inavlid");
		}
	}
	}
