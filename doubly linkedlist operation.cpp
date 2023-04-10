#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
   struct node *prev;
};
struct node *head=NULL;
//struct node *tail;
struct node *create(struct node *);
struct node *disply(struct node *);
struct node *insbeg(struct node *);
struct node *insend(struct node *);
struct node *insatpos(struct node *);
struct node *delbeg(struct node *);
struct node *delend(struct node *);
struct node *delatpos(struct node *);
struct node *Reverse(struct node *);

struct node *Reverse(struct node *head)
{
    struct node *cptr,*nptr;
    cptr =head;
    nptr=cptr->next;
    cptr->next=NULL;
    cptr->prev=nptr;
    
    while(nptr!=NULL)
    {
        nptr->prev=cptr->next;
        nptr->next=cptr;
        cptr=nptr;
        nptr=nptr->prev;
    }
    head=cptr;
    return head;
}

struct node *delatpos(struct node *head)
{  
  
  int i,pos;
   printf("\nEnter the position:");
   scanf("%d",&pos);
   if(pos==1)
   {
      head=delbeg(head);
   }
   else
   {
     struct node *ptr;
     ptr=head;
     for(i=1;i<pos-1;i++)
     {
         ptr=ptr->next;
     }
     ptr->prev->next=ptr->next;
     ptr->next->prev=ptr->prev;
     free(ptr);
     return head;
   }
     
}

struct node *delend(struct node *head)
{
    struct node *ptr;
    ptr=head;
    while(ptr->next !=NULL)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    return head; 
}

struct node *delbeg(struct node *head)
{
    struct node *ptr;
    ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
    return head;
}

struct node *insatpos(struct node *head)
{
   int i,pos;
   printf("\nEnter the position:");
   scanf("%d",&pos);
   if(pos==1)
   {
      head=insbeg(head);
   }
   else
   {
     struct node *new_node,*ptr;
     ptr=head;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&new_node->data);
     new_node->next=NULL;
   // new_node->prev=NULL;
    for(i=1;i<pos-1&&ptr!=NULL;i++)
    {
        ptr=ptr->next;
    }
    new_node->prev=ptr;
    new_node->next=ptr->next;
    ptr->next=new_node;
    new_node->next->prev=new_node;
   }
   return head;
}

struct node *insend(struct node *head)
{
    struct node *new_node, *ptr;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    new_node->prev=NULL;
    ptr=head;
    while(ptr->next !=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=new_node;
    new_node->prev=ptr;
    return head;
}
struct node *insbeg(struct node *head)
{
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    new_node->prev=NULL;
    head->prev=new_node;
    new_node->next=head;
    head=new_node;
    return head;
}

struct node *disply(struct node *head)
{
    struct node *ptr;
    ptr=head;
    printf("\nDoubly linked list:");
    while(ptr !=NULL)
    {
        printf("\t%d",ptr->data);
        ptr=ptr->next;
    }
    return head;
}

struct node *create(struct node *head)
{

    struct node *new_node, *ptr;
    int ch;
    do 
    {
     new_node=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    new_node->prev=NULL;
    if(head==NULL)
    {
      head=ptr=new_node;  
    }
    else
    {
        ptr->next=new_node;
        new_node->prev=ptr;
        ptr=new_node;
    }
    printf("Do you want to continue?(1)");
    scanf("%d",&ch);
    }while(ch==1);
    return head;
    
}

int main()
{
    int ch;
    while("h")
    {
        printf("\n\n*******___ALL MENU____*******");
		printf("\n =====================================");
		printf("\n 1: Create list");
		printf("\n 2: Insert a node at the begining");
		printf("\n 3: Insert a node at the end");
	//	printf("\n 4: Insert after a node");
	//	printf("\n 5: Insert before a node");
		printf("\n 6: Insert a node at nth position");
		printf("\n 7: Delete a node from the begining");
		printf("\n 8: Delete a node from the end");
		printf("\n 9: Delete a node at any position ");
	//	printf("\n 10: Display the list");
	//	printf("\n 11: sorting the linked list");
		printf("\n 12: Reverse order ");
	//	printf("\n 13: Another create list");
	//	printf("\n 14: node searching");
	//	printf("\n 15: concatenation");
		printf("\n 16:End of the program");
		printf("\n =====================================");
		printf("\n\t: Enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1: head=create(head);
		            head=disply(head);
		            break;
		    case 2: head=insbeg(head);
		            head=disply(head);
		            break;
		    case 3: head=insend(head);
		            head=disply(head);
		            break;
		    case 6: head=insatpos(head);
		            head=disply(head);
		            break;
		    case 7: head=delbeg(head);
		            head=disply(head);
		            break; 
		    case 8: head=delend(head);
		            head=disply(head);
		            break;
		    case 9: head=delatpos(head);
		            head=disply(head);
		            break;
		    case 12:head=Reverse(head);
		            head=disply(head);
		            break;       
		    case 16: exit(0);
		            break;
		}
		
    }
}
