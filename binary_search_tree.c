#include <stdio.h>
#include <stdlib.h>

struct node 
{
    struct node * lchild;
    int data;;
    struct node * rchild;
};

void insert(struct node *root, struct node * new_node);
void preorder(struct node * root);
void inorder(struct node * root);
void postorder(struct node * root);
struct node * findMIN(struct node * root);
struct node * delete(struct node * root, int key);

int main()
{
    struct node * root = NULL;
    struct node * new, * temp;
    int choice, data, key;
    do
    {
        printf("1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.findMIN\n6.Delete\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            new = (struct node *)malloc(sizeof(struct node));
            printf("Enter data: ");
            scanf("%d", &new->data);
            new->lchild = new->rchild = NULL;
            if(root==NULL)
            {
                root = new;
            }
            else
            {
                insert(root,new);
            }
            break;

            case 2:
            inorder(root);
            printf("\n");
            break;

            case 3:
            preorder(root);
            printf("\n");
            break;

            case 4:
            postorder(root);
            printf("\n");
            break;

            case 5:
            temp = findMIN(root);
            printf("%d\n",temp->data);
            break;

            case 6:
            printf("Enter data to delete: ");
            scanf("%d", &key);
            if(root==NULL)
            {
                printf("BST is empty!!\n");
            }
            else
            {
                root = delete(root,key);
                printf("%d is deleted\n", key);
            }
            break;
        }
    } while (choice!=8);
}

void preorder(struct node * root)
{
    if (root!=NULL)
    {
        printf("%d->",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}

void postorder(struct node * root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d->",root->data);
    }
}

void inorder(struct node * root)
{
    if (root!=NULL)
    {
        inorder(root->lchild);
        printf("%d->",root->data);
        inorder(root->rchild);
    }
}

void insert(struct node * root, struct node *new_node)
{
    if (new_node->data<root->data)
    {
        if (root->lchild==NULL)
        {
            root->lchild=new_node;
        }
        else
        {
            insert(root->lchild,new_node);
        }
    }
    else if (new_node->data>root->data)
    {
        if (root->rchild==NULL)
        {
            root->rchild=new_node;
        }
        else
        {
            insert(root->rchild,new_node);
        }
    }
}

struct node * findMIN(struct node * root)
{
    struct node *temp;
    temp=root;
    while (temp->lchild!=NULL)
    {
        temp=temp->lchild;
    }
    return temp;
}

struct node * delete(struct node * root, int key)
{
    struct node *temp;
    if (key<(root->data))
    {
        root->lchild=delete(root->lchild,key);
    }
    else if (key>(root->data))
    {
        root->rchild=delete(root->rchild,key);
    }
    else
    {
        if (root->lchild==NULL && root->rchild==NULL)
        {
            printf("\nDeleting leaf node\n");
            free(root);
            return NULL;
        } 
        else if (root->lchild==NULL)
        {
            printf("\nDeleting node with 1 right child\n");
            temp=root;
            root=root->rchild;
            free(temp);
            return root;
        }
        else if (root->rchild==NULL)
        {
            printf("\nDeleting node with 1 left child\n");
            temp=root;
            root=root->lchild;
            free(temp);
            return root;
        }
        else
        {
            printf("\nDeleting node with 2 children\n");
            temp=findMIN(root->rchild);
            root->data=temp->data;
            root->rchild=delete(root->rchild,temp->data);
        }
        return root;
    }
}