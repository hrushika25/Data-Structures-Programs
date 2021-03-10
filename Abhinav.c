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

//insert_beg
void insert_beg()
{
	create_node();
	//1st node
	if(start==NULL)
	{
		start = temp;
	}
	else	//many nodes
	{
		// creating link
		temp->rlink = start;
		start->llink = temp;
		start = temp;
	}

}

//insert at any node
void insert_pos()
{
	int count = 0,pos;
	ptr = start;
	while(ptr!=NULL) 	// counting nodes
	{
		count++;
		ptr = ptr->rlink;
	}
	printf("\nEnter Position:");
	scanf("%d",&pos);
	//1st pos	
	if(pos == 1)
		insert_beg();
	else if(pos == count +1)	//ending insertion
		insert_end();
	else if(pos>1 && pos<=count)	//general case
	{
		int i;
		ptr = start;
		for(i=1;i<pos-1;i++)	//transversing to one previous node than pos
		{
			ptr = ptr->rlink;
		}
		create_node();
		//linking
		temp ->rlink = ptr->rlink;
		temp->llink = ptr;
		ptr->rlink = temp;
		temp->rlink->llink = temp;
		
	}
	else
	{
		printf("invalid position");
	}
}
//delete beg
void delete_beg()
{
	//no node present
	if(start == NULL)
		printf("List is Empty");
	else if(start->rlink == NULL)	//only 1 node present
	{
		free(start);
		start = NULL;
	}
	else	//general case
	{
		ptr = start;
		start = start->rlink;
		start->llink = NULL;
		free(ptr);
	}
}
//delete end
void delete_end()
{
	//no node present
	if(start == NULL)
		printf("List is Empty");
	else if(start->rlink == NULL)	//only 1 node present
	{
		free(start);
		start = NULL;
	}
	else	//general case
	{
		ptr = start;
		while(ptr->rlink!=NULL) //traversing to last node
		{
			ptr = ptr->rlink;
		}
		cur = ptr->llink;
		cur->rlink = NULL;
		free(ptr);
		
	}
	
}

//delte any position
void delete_pos()
{
	int count = 0,pos;
	ptr = start;
	while(ptr!=NULL) 	// counting nodes
	{
		count++;
		ptr = ptr->rlink;
	}
	printf("\nEnter Position:");
	scanf("%d",&pos);
	if(pos == 1)
		delete_beg();
	else if(pos == count)
		delete_end();
	else if(pos>1 && pos<count)
	{
		int i;
		ptr = start;
		for(i=1;i<pos;i++)
			ptr = ptr->rlink;

		ptr->llink->rlink = ptr->rlink;
		ptr->rlink->llink = ptr->llink;
		free(ptr);
	}
	else
		printf("INVALID POSITION!");
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
		printf("%d<-->\n",ptr->data);	//for last element
		
	}
}
//main fn
void main()
{
	int choice;
	printf("\t\tDOUBLY LINK LIST\n");
	while(1)
	{	printf("1.Insert at the end\n2.Display\n3.Insert At beg\n4.Delete at beg\n5.Delete at end\n6.Insert at any Position\n7.Delete at any position\n8.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: insert_end();
				break;
			case 2: display();
				break;
			case 3: insert_beg();
				break;
			case 4: delete_beg();
				break;
			case 5: delete_end();
				break;
			case 6: insert_pos();
				break;
			case 7: delete_pos();
				break;
			case 8: exit(0);
				break;			
			default: printf("INVALID INPUT");
		}
	}
}