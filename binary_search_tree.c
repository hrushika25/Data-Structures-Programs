#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*llink;
    struct node*rlink;
};
struct node *temp,*parent,*root=NULL,*tree,*ptr;
void create_bs()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&temp->data);
    temp->llink=temp->rlink=NULL;

    if(root == NULL)
    {
        root=temp;
    }
    else
    {
        ptr=root;
        while(ptr != NULL)
        {
            parent =ptr;
            if(ptr->data==temp->data)
            {
                printf("Found node\n");return;
            }
            else
            {
                if(temp->data<ptr->data)
                {
                    ptr=ptr->llink;
                }
                else
                {
                    ptr=ptr->rlink;
                }
                
            }
            
        }
        if(parent->data > temp->data)
        {
            parent->llink = temp;
        }
        else
        {
            parent->rlink = temp;
        }
        
    }
    
}
void inorder(struct node *tree)
{   if(tree != NULL)
    {
        inorder(tree->llink);
        printf("%d ",tree->data);
        inorder(tree->rlink);
    }
}

int main()
{   int i=0,ch;
    printf("enter how many elements : ");
    scanf("%d",&ch);
    while(i!=ch)
    {
        create_bs();
        i++;
    }
    printf("the whole treeeeeee is\n");
    inorder(root);
    return 0;

}