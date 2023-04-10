#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node *next;
   struct node *prev;
};
struct node *create(struct node*);
struct node *display(struct node*);
struct node *concate(struct node*,struct node*);


struct node *concate(struct node*head,struct node*head1)
{
	struct node *ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=head1;
	head1->prev=ptr;
	return head;
}



struct node *display(struct node*sam)
{
	struct node *ptr=sam;
	printf("\n Doubly linked list:");
	while(ptr!=NULL)
	{
		printf("\t %d",ptr->data);
		ptr=ptr->next;
	}
	return sam;
	
}

struct node *create(struct node*head)
{
	struct node*new_node,*ptr;
	head=NULL;
	int val,ch;
	do{
		printf("\n Enter the value:");
		scanf("%d",&val);
		new_node=(struct node*)malloc(sizeof(struct node*));
		new_node->data=val;
		new_node->prev=NULL;
		new_node->next=NULL;
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
    struct node *head,*head1;
	int ch;
    while("ch")
    {
        printf("\n\n*******___ALL MENU____*******");
		printf("\n =====================================");
		printf("\n 1: Create doubly linked list.");
		printf("\n 2: Display. ");
		printf("\n 3: Create another doubly linked list.");
        printf("\n 4: Concatenation.");
		printf("\n 5: End of the program");
		printf("\n =====================================");
		printf("\n\t: Enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1: head=create(head);
			        break;
		    case 2: head= display(head);
		            break;
		    case 3: head1 = create(head);
		       printf("\n Another");
		        head1= display(head1);
		            break;
		    case 4: head=concate(head,head1);
			    
		            break;
		            
	
		    case 5: exit(0);
		            break;
		}
		
    }
}
