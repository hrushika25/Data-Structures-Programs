#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*link;

};
struct node *start=NULL,*temp=NULL,*ptr=NULL;
int i;
void data_call()              //CREATION OF NODE
{
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data ");
    scanf("%d",&temp->data);
    temp->link=NULL;
}
void insert_end()
{
    data_call();
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;

    }

}
void insert_beg()
{
    data_call();
    if(start==NULL)
    {
    start=temp;
    }
    else
    {
        temp->link=start;
        start=temp;
    }
}
void insert_pos()
{
    int pos,count=0;
    printf("enter position\n");
    scanf("%d",&pos);
    ptr=start;
    while(ptr->link!=NULL)
    {
        count++;
        ptr=ptr->link;
        
    }
    count++;
    if(pos==1)
        insert_beg();
    else if(pos==count+1)
        insert_end();
    else if(pos>1 && pos<= count)
    {   data_call();
        ptr=start;
        for(i=1;i<pos-1;i++)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;

    }
    else
        printf("wrong position");


}
void display()
{
    ptr=start;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->link;

    }
}

int main()
{
    int n;
    while(1)
    {
          printf("\nenter choice\n1.insert_beg\n2.insert_end\n3.insert_pos\n4.display\n5.exit ");
            scanf("%d",&n);
        switch(n)
        {
            case 1:insert_beg();
                    break;
            case 2:insert_end();
                    break;
            case 3:insert_pos();
                    break;
            case 4:display();
                    break;
            case 5:exit(0);
                    break;

        }
    }
    return 0;
}