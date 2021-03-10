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
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        ptr->link=temp;

    }

}
void delete_second()
{	int count=0;
    if (start==NULL)
	{
		printf("the list is empty");
	}
	else
	{  
         while(ptr->link!=NULL)
    {
        
        ptr=ptr->link;
        count++;
        
    }
    
    ptr=start;    

    for(i=0;i<=count/2;i++)
    {
		temp=ptr->link;
		ptr=ptr->link->link;
        free(temp);
    
    }
    ptr=start;
    
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->link;

    }
		
	}
}


int main()
{
    int n;
    while(1)
    {
          printf("\nenter choice\n1.insert\n2.delete_second\n3.exit ");
            scanf("%d",&n);
        switch(n)
        {
            case 1:list_creation();
                    break;
            case 2:delete_second();
                    break;
            case 3:exit(0);
                    break;

        }
    }
    return 0;
}