#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start=NULL;

void insert_beg();
void insert_end();
void insert_after();
void delete();
void update();
void display();

int main()
{
    int choice;
    do
    {
        printf("\n1.Insert Beg\n2.Insert End\n3.Insert After\n4.Delete\n5.Update\n6.Display\nEnter Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert_beg();
            display();
            break;
            case 2:
            insert_end();
            display();
            break;
            case 3:
            insert_after();
            display();
            break;
            case 4:
            delete();
            display();
            break;
            case 5:
            update();
            display();
            break;
            case 6:
            display();
            break;
        }
    }
    while (choice!=7);
}

void display()
{
    struct node *temp;
    temp=start;

    while(temp->next!=start)
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }
    printf("\n%d",temp->data);
}

void insert_beg()
{
    struct node *new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    printf("\nEnter Value: ");
    scanf("%d",&new_node->data);
    if(start==NULL)
    {
        new_node->next=new_node;
        start=new_node;
    }
    else
    {   
        temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=start;
        start=new_node;
    }
}

void insert_end()
{
    struct node*new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    struct node *temp;
    printf("\nEnter Value: ");
    scanf("%d",&new_node->data);
    if(start==NULL)
    {
        new_node->next=new_node;
        start=new_node;
    }
    else
    {
        temp=start;
        while(temp->next!=start)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=start;
    }
}

void update()
{
    struct node*temp;
	int element;
	printf("\nEnter node which is to be updated: ");
	scanf("%d",&element);
	temp=start;
	while(temp->data!=element)
	{
		temp=temp->next;
	}
	printf("\nEnter new Value: ");
	scanf("%d",&temp->data);
}

void insert_after()
{
    struct node *temp;
    struct node *new_node;
    int element;
    printf("\nEnter element after which you want to insert: ");
    scanf("%d",&element);

    new_node=(struct node*)malloc(sizeof(new_node));
    printf("\nEnter new value: ");
    scanf("%d",&new_node->data);

    temp=start;
    while(temp->data!=element)
    {
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
}

void delete()
{
    struct node *temp,*ptemp,*ntemp;
    int element;
    printf("\nEnter node to delete: ");
    scanf("%d",&element);

    if(element==start->data)
    {
        if(start->next==start)
        {
            temp=start;
            start=NULL;
            free(temp);
        }
        else
        {
            temp=start;
            start=start->next;
            ntemp=temp;
            while(ntemp->next!=temp)
            {
                ntemp=ntemp->next;
            }
            ntemp->next=start;
            free(temp);
        }
    }
    else
    {
        temp=start;
        while(temp->data!=element)
        {
            ptemp=temp;
            temp=temp->next;
        }
        ptemp->next=temp->next;
        free(temp);   
    }
}