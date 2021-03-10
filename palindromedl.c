#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*llink;
    struct node*rlink;
};
struct node *start=NULL,*last,*ptr=NULL,*temp,*first;

void data_call()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d",&temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;
}
void list_creation()
{
    data_call();
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->rlink!=NULL)
        {
            ptr=ptr->rlink;
        }
        ptr->rlink=temp;
        temp->llink=ptr;
    }
}
void display()
{
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d  ",ptr->data);
        ptr=ptr->rlink;
    }
}
void ispalin()
{   int flag=0,count=1,i;
    ptr=start;
    while(ptr->rlink!=NULL)
    {
        ptr=ptr->rlink;
        count++;
    }
    last=ptr;
    first=start;
    for(i=0;i<count/2;i++)
    {
        if(last->data!=first->data)
        {  
            flag++;
            break;
        }
        else
        {
        
        first=first->rlink;
        last=last->llink;
        }
    }
    if(flag==0)
    {
        printf("\nits a pallindrome\n");
    }
    else
    {
        printf("\nits not a pallindrome");
    }
}
void main()
{   int n;
    while(1)
    {   
        printf("\nenter choice\n1.create list\n2.display\n3.pallindrome or not\n4.exit");
        scanf("%d",&n);
        switch(n)
        {
            case 1:list_creation();
                    break;
            case 2:display();
                    break;
            case 3:ispalin();
                    break;
            case 4:exit(0);
                    break;
        }
    }
}