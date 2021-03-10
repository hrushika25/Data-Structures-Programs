#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*llink;
    struct node*rlink;
}node;
node *root,*tree,*temp;
int isleftchild(node *tree)
{   int ch;
    printf("Do you want a left child of %d ",tree->data);
    printf("\nEnter 1 for yes and 0 for no ");
    scanf("%d",&ch);

    if(ch==1)
        return 1;
    else
        return 0;
}
int isrightchild(node *tree)
{   int ch;
    printf("Do you want a right child of %d ",tree->data);
    printf("\nEnter 1 for yes and 0 for no ");
    scanf("%d",&ch);

    if(ch==1)
        return 1;
    else
        return 0;
    
}
void create(node *tree)
{
    if(isleftchild(tree)==1)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter data for left child: ");
        scanf("%d",&temp->data);
        tree->llink=temp;
        create(temp);
    }
    else
    {
        tree->llink=NULL;
    }
    if(isrightchild(tree)==1)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for right child: ");
        scanf("%d",&temp->data);
        
        tree->rlink=temp;
        create(temp);
     }
    else
    {
        tree->rlink=NULL;
    }
}

void inorder(node *tree)
{   if(tree != NULL)
    {
        inorder(tree->llink);
        printf("%d ",tree->data);
        inorder(tree->rlink);
    }
}

void postorder(node *tree)
{   
    if(tree != NULL)
    {
        postorder(tree->llink);
        postorder(tree->rlink);
        printf("%d ",tree->data);
    }
}

void preorder(node *tree)
{
    if(tree != NULL)
    {
        printf("%d ",tree->data);
        preorder(tree->llink);
        preorder(tree->rlink);
    }
}

int main()
{   root = (struct node*)malloc(sizeof(struct node));
    printf("Enter data for first node: ");
    scanf("%d",&root->data);
    root->llink = root->rlink = NULL;

    create(root);
    printf("\nthe inorder of this tree is: "); inorder(root);
    printf("\nthe preorder of this tree is: "); preorder(root);
    printf("\nthe postorder of this tree is: "); postorder(root);
    printf("\n");
    return 0;
}