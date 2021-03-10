#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*llink;
    struct node*rlink;
}node;
struct node *start=NULL,*temp,*ptr=NULL;

void insert_order()
{
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;

    if(start == NULL)
    {
        start=temp;
    }
    else 
    if(temp->data < start->data)
    {
        temp->rlink=start;
        start->llink=temp;
    
        start=temp;    
    }
    else 
    {   
        ptr=start;
        while((temp->data > ptr->data)&&(ptr->rlink!=NULL))
        {
            ptr=ptr->rlink;
            
        }
        if(temp->data > ptr->data)
        {
            ptr->rlink=temp;
            temp->llink=ptr;
        }
        else
        {
            temp->llink=ptr->llink;
            ptr->llink->rlink=temp;
            temp->rlink=ptr;
            ptr->llink=temp;
        }    
    }
}
void display()
{
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->rlink;
    }
}
int main()
{   int n;
    while(1)
    {
        printf("\nenter choice\n1.insert in ordered list\n2.display\n3.exit\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:insert_order();
                    break;
            case 2:display();
                    break;
            case 3:exit(0);
                    break;
            default:printf("Wrong input");
                    break;

        }
    }
    return 0;

}