#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*llink;
    struct node*rlink;
};
struct node *start=NULL,*temp,*ptr,*cur;
int i;
void data_call()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data ");
    scanf("%d",&temp->data);
    temp->rlink=temp->llink=NULL;

}
void insert_beg()
{   data_call(); 
    //1st node
	if(start==NULL)
	{
		start = temp;
	}
    else
    {
        temp->rlink=start;
        start->llink=temp;
        start=temp;
    }
}
void insert_end()
{   data_call();
     ptr=start;
     while(ptr!=NULL)
     {
         ptr=ptr->rlink;
     }
     ptr=temp;
     temp->llink=ptr;

}
void insert_pos()
{   int count=0,pos;
    data_call();
    printf("enter the position");
    scanf("%d",&pos);
    ptr=start;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->rlink;
    }
    if(pos==1)
    {
        insert_beg();
    }
    else if(pos==count+1)
    {
        insert_end();
    }
    else if(pos>1 && pos<=count)
    {
        ptr=start;
        for(i=1;i<pos;i++)
        {
            
            ptr=ptr->rlink;
        }
        temp->llink=ptr->llink;
        temp->rlink=ptr;
        ptr->llink->llink=temp;
        ptr->llink=temp;

    }
    else
    printf("wrong position");

}
void delete_beg()
{   if(start==NULL)
    {
        printf("list is empty");

    }
    else if(start->rlink==NULL)
    {
        start=NULL;
    } 
    else
    {
    ptr=start;
    start=start->rlink;
    free(ptr);
    }
}
void delete_end()
{
   if(start==NULL)
    {
        printf("list is empty");
    }
    else if(start->rlink==NULL)
    {
        free(start);
        start=NULL;
    }
    else
    {
        ptr=start;
        while(ptr->rlink!=NULL)
        {
            ptr=ptr->rlink;
        }
        cur=ptr->llink;
        cur->rlink=NULL;
        free(ptr);
    }
     
}
void delete_pos()
{   int count=0,pos;
    printf("Enter position\n");
    scanf("%d",&pos);
    if(pos == 1)
    {
        delete_beg();
        
    }
    else if(pos==count)
    {
        delete_end();

    }
    else if(pos>1&&pos<count)
    {
    for(i=1;i<count;i++)
    {
        ptr=ptr->rlink;
    }
    cur=ptr->llink;
    cur->rlink=ptr->rlink;
    ptr->rlink->llink=cur;
    free(ptr);        
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
{ int choice;
    while(1)
 {
    printf("\nenterchoice\n1.insert at beginning\n2.insert at end\n3.insert at any position\n4.delete at beginning\n5.delete at end\n6.delete at any position\n7.display\n8.exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: insert_beg();
                break;
        case 2: insert_end();
                break;
        case 3:insert_pos();
                break;
        case 4:delete_beg();
                break;
        case 5: delete_end();
                break;
        case 6: delete_pos();
                break;
        case 7:display();
                break;
        case 8:exit(0);
                break;

            }
 }  
    return 0;
}
