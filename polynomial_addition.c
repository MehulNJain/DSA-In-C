#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int coef, exp;
};

struct node *poly1 = NULL, *poly2 = NULL, *result = NULL;

void insert1();
void insert2();
void insert3(int c, int e);
void display();
void addition();

int main() {
    insert1();
    insert2();
    addition();
    display();
    return 0;
}

void insert1() {
    int n, i;
    printf("Enter no of terms in poly1: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        struct node *temp = poly1, *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter coefficient and exponent: ");
        scanf("%d %d", &newnode->coef, &newnode->exp);
        newnode->next = NULL;

        if (poly1 == NULL)
            poly1 = newnode;
        else {
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

void insert2() {
    int n, i;
    printf("\nEnter no of terms in poly2: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        struct node *temp = poly2, *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter coefficient and exponent: ");
        scanf("%d %d", &newnode->coef, &newnode->exp);
        newnode->next = NULL;

        if (poly2 == NULL)
            poly2 = newnode;
        else {
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
}

void addition() {
    struct node *p = poly1, *q = poly2;
    while (p != NULL && q != NULL) {
        if (p->exp > q->exp) {
            insert3(p->coef, p->exp);
            p = p->next;
        } else if (q->exp > p->exp) {
            insert3(q->coef, q->exp);
            q = q->next;
        } else {
            insert3(p->coef + q->coef, p->exp);
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL) {
        insert3(p->coef, p->exp);
        p = p->next;
    }
    while (q != NULL) {
        insert3(q->coef, q->exp);
        q = q->next;
    }
}

void insert3(int c, int e) {
    struct node *temp = result, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->coef = c;
    newnode->exp = e;
    newnode->next = NULL;

    if (result == NULL) {
        result = newnode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void display() {
    struct node *temp = result;
    printf("\nResult: ");
    while (temp != NULL) {
        printf("%dx^%d", temp->coef, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}
