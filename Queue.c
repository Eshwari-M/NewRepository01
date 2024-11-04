#include <stdio.h>
#include <stdlib.h>
int *q;
int max,front=0,count=0,rear=-1;
void enqueue()
{
	int ele;
	if(count==max)
	{
		printf("Queue overflow");
	}
	else
	{
		printf("Enter ele to insert=");
		scanf("%d",&ele);
		rear=(rear+1)%max;
		q[rear]=ele;
		count++;
	}
}
void dequeue()
{
	if(count==0)
	{
		printf("Queue underflow");
	}
	else
	{
		printf("Deleted ele is %d",q[front]);
		front=(front+1)%max;
		count--;
	}
}
void display()
{
  int i,k;
  if(count==0)
	{
		printf("Queue is empty");
	}
	else
	{
	k=front;
	for(i=0;i<count;i++)
	{
	printf("%d\n",q[k]);
	k=(k+1)/max;
}
}
}
void main()
{
	int ele,choice;
	printf("Enter max=");
	scanf("%d",&max);
	q=(int*)malloc(max*sizeof(int));
	while(1)
	{
		printf("\n Enter choice:");
		printf("\n 1 for enq\n 2 for deq \n 3 for display \n 4 for exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:enqueue();
			        break;
			case 2:dequeue();
			break;
			case 3: display();
			break;
			case 4:free(q);
			exit(0);
			break;
			default:printf("Inavlid");
		}
	}
	}
