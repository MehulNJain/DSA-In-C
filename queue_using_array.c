#include<stdio.h>
#include<stdlib.h>

int front=-1;
int rear=-1;

int Q[5];

void enqueue()
{
    if(rear==4)
    {
        printf("Queue Overflow !!!\n");
        return;
    }
    if(front==-1&&rear==-1)
    {
        front++;
        rear++;
        printf("Enter element: ");
        scanf("%d",&Q[rear]);
    }
    else
    {
        rear++;
        printf("Enter element: ");
        scanf("%d",&Q[rear]);
    } 
}

void dequeue()
{
    if (front==-1&&rear==-1)
    {
        printf("Queue Underflow !!!\n");
    }
    if(front==rear)
    {
        printf("%d is deleted\n",Q[front]);
        front=-1;
        rear=-1;
    }
    else{
        printf("%d is deleted\n",Q[front]);
        front++;
    }
}

void display()
{
    printf("Queue elements are: \n");
    int i;
    if (front==-1&&rear==-1)
    {
        printf("Queue Underflow !!!\n");
        return;
    }
    else{
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",Q[i]);
        }
    }
}

int main()
{
    int k;
    while (1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            enqueue();
            display();
            break;

            case 2:
            dequeue();
            display();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
        }
    }
    return 0;
}