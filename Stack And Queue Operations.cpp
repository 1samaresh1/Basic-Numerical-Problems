#include<stdio.h>
#include<stdlib.h>
//#include<malloc.h>
#define max_disk 5
#define max 5
struct node 
{
    int data;
    struct node *next;
}*top=NULL,*front=NULL;
 

int st[max_disk],tops=-1;
int que[max];
int front1=-1,rear1=-1;
void push_array(int ar[]);
void pop_array(int ar[]);
void peek_array(int ar[] );
void display_array(int ar[] );
struct node *push_link(struct node *);
struct node *pop_link(struct node *);
int peek_link(struct node *);
struct node *display_link(struct node *);
void ins_array(int que[]);
void del_array(int que[]);
void front_array(int que[]);
void display__array(int que[]);
struct node *ins_link(struct node *);
struct node *del_link(struct node *);
int for_link(struct node *);
struct node *display__link(struct node *);

struct node *display__link(struct node *front)
{
   struct node *ptr;
   ptr=front;
   printf("\nQUEUE:");
   while(ptr!=NULL)
   {
   	printf("\t%d",ptr->data);
   	ptr=ptr->next;
   }
   return front;	
}

int for_link(struct node *front)
{
	if(front==NULL)
	{
		printf("\Empty.");
	}
	else
	{ 
		printf("\n Front number at the queue is %d",front->data);
	}
	return 0;
}

struct node *del_link(struct node *front)
{   
    struct node *ptr;
     ptr=front;
	if(ptr==NULL)
	{
		printf("\n UNDERFLOW.");
	}
	else
	{ 
	   // ptr=front;
		front=front->next;
		printf("\n Deleted number from the queue is %d",ptr->data);
		free(ptr);	
	}
	return front;
}

struct node *ins_link(struct node *front)
{
	struct node *rear,*new_node;
	int val,x;
	rear=front;
	do
	{
	printf("\n Enter the number in the queue:");
	scanf("%d",&val);
   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data =val;
   new_node->next=NULL;
   if(rear==NULL)
   {
   	 // new_node->next=NULL;
   	  front=rear=new_node;
	} 
	else
	{    while(rear->next!=NULL)
	    {
	    	rear=rear->next;
		}
		rear->next=new_node;
		rear=rear->next;
		}
		printf("\n Do you want to continue{5|6}:");
    scanf("%d",&x);
    }while(x==5);
   return front; 	
}

void display__array(int que[])
{   int i;
	printf("\n QUEUE:");
	if(front1==-1 || front1>rear1)
	   {
	   	printf("\Empty.");
	   }
	   else
	   {
	   	for(i=front1;i<=rear1;i++)
	   	printf("\t %d",que[i]);
	   }
}
void front_array(int que[])
{   int num;
	 if(front1=-1 || front1>rear1)
	   {
	   	printf("\Empty.");
	   }
	   else
	   {
	   	num=que[front1];
	   	printf("\n The front value in the queue is %d",num);
	   }
}

void del_array(int que[])
{
      int num;
	   if(front1=-1 || front1>rear1)
	   {
	   	printf("\n UNDERFLOW.");
	   }
	   else
	   {
	   	num=que[front1];
	   	printf("\n Deleted number is =%d",num);
	   	front1++;
	   	}	
}

void ins_array(int que[])
{
	int val,x;
	do
	{
		
	printf("\n Enter the element to be inserted in the queue:");
	scanf("%d",&val);
	if(rear1==max-1)
	{
		printf("\n OVERFLOW.");
	}
	else
	 if(rear1==-1 && front1==-1)
	{
	   front1=rear1=0;
	   que[rear1]=val;	
	}
	else
	{
		rear1++;
		que[rear1]=val;
	}
	//que[rear1]=val;
	printf("\n Do you want to continue{5|6}");
	scanf("%d",&x);
  }while(x==5);
}

struct node *display_link(struct node *top)
{
    struct node *ptr;
    ptr=top;
    if(top==NULL)
    {
        printf("\n Empty stack.");
        
    }
    else
    {   printf("\nSTACK");
        while(ptr!=NULL)
        {
            printf("\n\t%d",ptr->data);
            ptr=ptr->next;
        }
    }
    return top;
}

int peek_link(struct node *top)
{
    if(top==NULL)
    {
        printf("\n Empty stack.");
        return -1;
    }
    else
    {
        printf("\nThe topest number of the stack=%d",top->data);
        
    }
}

struct node *pop_link(struct node *top)
{
    struct node *ptr;
    ptr=top;
    if(top==NULL)
    {
        printf("\n STACK UNDERFLOW.");
    }
    else
    {
      top=top->next;
      printf("The value deleted from thr stack=%d",ptr->data);
      free(ptr);
    }
    return top;
}

struct node *push_link(struct node *top)
{
    struct node *new_node;
    int val,x;
    do
    {
    printf("\nEnter the number to be pushed on stack:");
    scanf("%d",&val);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=val;
    if(top==NULL)
    {
        new_node->next=NULL;
        top=new_node;
    }
    else
    {
        new_node->next=top;
        top=new_node;
    }
    printf("\n Do you want to continue{5|6}:");
    scanf("%d",&x);
    }while(x==5);
   return top; 
}

void display_array(int ar[] )
{
  int i;
  if(tops==-1)
  {
     printf("\nSTACK IS EMPTY.");  
  }
  else
  {    
      printf("\nSTACK");
      for(i=tops;i>=0;i--)
      {
          printf("\t%d",ar[i]);
          printf("\n");
      }
  }
  
}


void peek_array(int ar[])
{
    if(tops==-1)
    {
        printf("\nSTACK IS EMPTY.");
        
    }
    else
    {
        printf("The topest number of the stack=%d", ar[tops]);
    }
    
}

void pop_array(int ar[])
{
   int val;
   if(tops==-1)
       {
          printf("\nSTACK UNDERFLOW.");
          
        }
       else
        {
          val=ar[tops];
          printf("\n The  deleted value from the stack is %d",val);
          tops--;          
        }
        
}

void push_array(int ar[] )
{
    int x,val;
  do 
  {
    printf("\nEnter the number to be pushed on stack:");
    scanf("%d",&val);
     if(tops==max_disk-1)
       {
          printf("\nSTACK OVERFLOW .");
        }
       else
        {
          tops++;
          ar[tops]=val;
        }
    printf("\n Do you want to continue{5|6}:");
    scanf("%d",&x);
  }while(x==5);
  
}

int main()
{
    int ch;
    back:
    while(12)
    {
    printf("\n*************MAIN MENU********************\n");
    printf("\n 1.Stacks implementation using Array.");
    printf("\n 2.Stacks implementation using Linkedlist.");
    printf("\n 3.Queues implementation using array.");
    printf("\n 4.Queues implementation using Linkedlist.");
    printf("\n 5 End of the program.");
    printf("\n********************************************\n");
    printf("\n Enter the option:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
             while(1)
             {
                printf("\n*************STACKS_ARRAY********************\n");
                printf("\n 1.push.");
                printf("\n 2.pop.");
                printf("\n 3.peek.");
                printf("\n 4.display.");
                printf("\n 5.Goto main menu");
                printf("\n********************************************\n");
                printf("\n Enter the option:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1: push_array(st);
                            break;
                    case 2:pop_array(st);
                            break;
                    case 3:peek_array(st);
                            break;
                    case 4:display_array(st);
                            break;
                    case 5: goto back;
                            break;
                    
                }
            }
             
             break;
        case 2:
           while(11)
             {
                printf("\n*************STACKS_LINKEDLIST****************\n");
                printf("\n 1.push.");
                printf("\n 2.pop.");
                printf("\n 3.peek.");
                printf("\n 4.display.");
                printf("\n 5.Goto main menu");
                printf("\n********************************************\n");
                printf("\n Enter the option:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1: top=push_link(top);
                            break;
                    case 2:top= pop_link(top);
                            break;
                    case 3:peek_link(top);
                            break;
                    case 4: top=display_link(top);
                            break;
                    case 5: goto back;
                            break;
                    
                }
             }break;
       case 3:
       	 while(1)
             {
                printf("\n*************QUEQES_ARRAY********************\n");
                printf("\n 1.Insert an element in a queues.");
                printf("\n 2.Delete an element from a queues.");
                printf("\n 3.Front element.");
                printf("\n 4.display.");
                printf("\n 5.Goto main menu");
                printf("\n********************************************\n");
                printf("\n Enter the option:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1: ins_array(que);
                            break;
                    case 2:del_array(que);
                            break;
                    case 3:front_array(que);
                            break;
                    case 4:display__array(que);
                            break;
                    case 5: goto back;
                            break;
                    
                }
            } break;
        case 4:
		 while(1)
             {
                printf("\n*************QUEQES_LINKED_LIST********************\n");
                printf("\n 1.Insert an element in a queues.");
                printf("\n 2.Delete an element from a queues.");
                printf("\n 3.Front element.");
                printf("\n 4.display.");
                printf("\n 5.Goto main menu.");
                printf("\n********************************************\n");
                printf("\n Enter the option:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1: front= ins_link(front);
                            break;
                    case 2:front= del_link(front);
                            break;
                    case 3:for_link(front);
                            break;
                    case 4:front=display__link(front);
                            break;
                    case 5: goto back;
                            break;
                    
                }
            } break; 
		case 5: exit(0);
		     break; 
    } 
    	
   }
   return 0;
}
