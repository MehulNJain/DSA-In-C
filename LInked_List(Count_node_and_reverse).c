#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node * start = NULL;

void insert_beg();
void count();
void reverse();

int main()
{
    int choice;
    do
    {
        printf("1.Insert Beg\n2.count\n3.reverse\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert_beg();
            display();
            break;
            case 2:
            count();
            display();
            break;
            case 3:
            reverse();
            display();
            break;
            case 4:
            display();
            break;

        }
    }
    while (choice!=5);
}

void insert_beg()
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&new_node->data);

    if (start==NULL)
    {
        new_node->next=NULL;
        start=new_node;
    }
    else 
    {
        new_node->next=start;
        start=new_node;
    }
}

void count()
{
    int i=0;
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    printf("\n The count is %d \n",i);
}

void reverse()
{
    struct node *ptemp,*temp;
    int item=0;
    temp=start;
    if(start->next!=NULL)
    {
        while(temp->next!=NULL)
        {
            ptemp=temp;
            temp=temp->next;
            item=temp->data;
            temp->data=ptemp->data;
            ptemp->data=item;
        }
        temp=start;
        item=temp->data;
        temp->data=ptemp->data;
        ptemp->data=item;
    }
}


void display()
{
    struct node*temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("\n%d\n",temp->data);
        temp=temp->next;
    }
}
