#include<stdio.h>
#include<stdlib.h>
// create structure node
typedef struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}node;

//initialize variables

node *start = NULL,*temp,*ptr,*cur;

// allocate memory in heap
void create_node()
{
	temp = (node*)malloc(sizeof(node));
	printf("\nEnter data:");
	scanf("%d",&temp->data);
	temp->rlink = temp->llink = NULL;
}

// create insert_end
void insert_end()
{
	create_node();
	// 1st node
	if(start==NULL)
	{
		start = temp;
	}
	else // many nodes
	{
		ptr = start;
		// comming to the last node
		while(ptr->rlink!=NULL)
			ptr = ptr->rlink;
		// creating link
		ptr->rlink = temp;
		temp->llink = ptr;				
		
	}
}
// create display
void display()
{
	// NO NODE
	if(start==NULL)
		printf("LINK IS NOT THERE");
	else	// NODE PRESENT
	{	
		ptr = start;
		while(ptr->rlink != NULL)
		{
			printf("%d<-->",ptr->data);
			ptr = ptr->rlink;
		}
		printf("%d\n",ptr->data);	//for last element
		
	}
}
//checks palindrome or not
void palindrome()
{
    int flag = 0,count = 1,i;// count begins from 1
    //if nothing
    if(start == NULL)
        printf("no list present!\n");
    else//intialize first and last variables
    {
        node *first,*last;
        ptr = first = start;
        //reaching last element and counting total no
        while(ptr->rlink!=NULL)
        {
            ptr = ptr->rlink;
            count++;
        }    
        last = ptr; // ptr is last.
        //checking 1st and last element and then decrement
        for(i = 0;i<count/2;i++)
        {
            if(first->data!=last->data)
            {
                flag++;
                break;
            }  
            else
            {
                first = first->rlink;
                last = last->llink;
            }
            
        }
        if(flag==0)
        {
            printf("\nits a pallindrome\n");
        }
        else
        {
            printf("\nits not a pallindrome\n");
        }
    }
}
//main fn
int main()
{
	int choice;
	printf("\t\tDOUBLY LINK LIST\n");
	while(1)
	{	printf("1.Insert at the end\n2.Display\n3.Palindrome or not\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert_end();
				break;
			case 2: display();
				break;
			case 3: palindrome();
				break;
            default: printf("Invalid choice");
        }
    }
}
