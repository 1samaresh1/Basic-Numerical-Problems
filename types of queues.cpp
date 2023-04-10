#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define max 5
void ins_link();
void del_link();
int peek_link();
void display_link();

struct node
{
	int data;
	struct node *next;
}*tail=NULL,*head=NULL;
int st[max];
int rear=-1,front=-1;
void ins_que(int st[] );
void del_que(int st[]);
void peek_que(int st[] );
void display_que(int st[] );
int fs[max],ss[max];
int topf=-1,tops=-1;
int count=0;
void enqueue();
void push1(int );
void dequeue();
int pop1();
int pop2();
void push2(int );
void display__que();
void peek__que();
int dq[max];
void ins_front();
void ins_rear();
void display();
void del_front();
void del_rear();
void getfront();
void getrear();
void ins_pque();
void del_pque();
void display_pque();

struct pq
{
	int data;
	int priority;
	struct pq *next;
}*start=NULL;

void display_pque()
{
	struct pq *ptr;
    ptr=start;
    if(start==NULL)
    {
        printf("\n Empty.");
        
    }
    else
    {   printf("\nQUEUE");
        do
        {
            printf("\t%d P{%d}",ptr->data,ptr->priority);
            ptr=ptr->next;
        }while(ptr!=NULL);
    }
}
void del_pque()
{
	struct pq *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("\n UNDERFLOW.");
	}else
	{
		start=start->next;
		printf("\n The deleted number is %d P{%d}",ptr->data,ptr->priority);
		free(ptr);
	}
}

void ins_pque()
{
	struct pq *new_node,*ptr;
	int p,n,z;
	do{
	
	new_node=(struct pq *)malloc(sizeof(struct pq));
	printf("\n Enter the number:");
	scanf("%d",&n);
	printf("\n Enter the priority:");
	scanf("%d",&p);
	new_node->data=n;
	new_node->priority=p;
	if(start==NULL||p<start->priority)
	{
		new_node->next=start;
		start=new_node;
		
	}
	else
	{
	   ptr=start;
	   while(ptr->next!=NULL&&ptr->next->priority<=p)
	   {
	   	   ptr=ptr->next;
     	}
     	new_node->next=ptr->next;
     	ptr->next=new_node;
	}
	printf("\n Do you want to continue{5|6}");
	scanf("%d",&z);
    }while(z==5);
}
void getrear()
{
	printf("\n raer number at the deque is %d",dq[rear]);
}

void getfront()
{
	printf("\n front number at the deque is %d",dq[front]);
}

void del_rear()
{
	if(front==-1&&rear==-1)
	{
		printf("\n Deque is Empty.");
	}else
	if(front==rear)
	{
		printf("\n Deleted number is %d",dq[rear]);
		front=rear=-1;
	}else
	if(rear==0)
	{
		printf("\n Deleted number is %d",dq[rear]);
		rear=0;
	}else
	{
		printf("\n Deleted number is %d",dq[rear]);
		rear--;
	}
}

void del_front()
{
	if(front==-1&&rear==-1)
	{
		printf("\n Deque is Empty.");
	}else
	if(front==rear)
	{
		printf("\n Deleted number is %d",dq[front]);
		front=rear=-1;
	}else
	if(front==max-1)
	{
		printf("\n Deleted number is %d",dq[front]);
		front=0;
	}else
	{
		printf("\n Deleted number is %d",dq[front]);
		front++;
	}
}

void display()
{
	int i=front;
	printf("\n DEQUE:");
	do
	{
		printf("\t%d{%d}",dq[i],i);
		i=(i+1)%max;
	}while(i !=rear);
	printf("\t%d{%d}",dq[rear],rear);
}

void ins_rear()
{
		int val,z;
	do{
	printf("\n Enter the data:");
	scanf("%d",&val);
	if((front==0 && rear==max-1)|| front==rear+1)
	{
		printf("\n Deque is full.");
	}else 
	if(front==-1&&rear==-1)
	{
		front=rear=0;
		dq[rear]=val;
	}
	else
	if(rear==max-1)
	{
		rear=0;
		dq[rear]=val;
	}
	else
	{
		rear++;
		dq[rear]=val;
	}
	printf("\n Do you want to continue{5|6}");
	scanf("%d",&z);
    }while(z==5);
}

void ins_front()
{
	int val,z;
	do{
	printf("\n Enter the data:");
	scanf("%d",&val);
	if((front==0 && rear==max-1)|| front==rear+1)
	{
		printf("\n Deque is full.");
	}else 
	if(front==-1&&rear==-1)
	{
		front=rear=0;
		dq[front]=val;
	}
	else
	if(front==0)
	{
		front=max-1;
		dq[front]=val;
	}
	else
	{
		front--;
		dq[front]=val;
	}
	printf("\n Do you want to continue{5|6}");
	scanf("%d",&z);
    }while(z==5);
}

void peek__que()
{
	printf("\n The topest number at queue is %d",fs[tops]);
}


void display__que()
{
	int i;
	printf("\n QUEUE:");
	for(i=0;i<=topf;i++)
	{
		printf("\t%d",fs[i]);
	}
}


void push2(int x)
{
	if(tops==max-1)
	{
		printf("\n OVERFLOW.");
	}
	else
	{
		tops++;
		ss[tops]=x;
	}
}


int pop1()
{
	int x;
	x=fs[topf--];
	return x;
}
int pop2()
{
	int x;
	x=ss[tops--];
	return x;
}

void dequeue()
{
	int i,a,b;
	if(topf==-1 && tops==-1)
	{
		printf("\n The queue is empty.");
	}
	else
	{
		for(i=0;i<count;i++)
		{
			a=pop1();
			printf("%d",a);
			push2(a);
		}
		b=pop2();
		printf("\n The deleted number from the queue is %d",b);
		count--;
		for(i=0;i<count;i++)
		{
			a=pop2();
			push1(a);
		}
	}
}


void push1(int x)
{
	if(topf==max-1)
	{
		printf("\n OVERFLOW.");
	}
	else
	{
		topf++;
		fs[topf]=x;
	}
}

void enqueue()
{
	int val,v;
	do
	{
	printf("\n Enter the data on the queue.");
	scanf("%d",&val);
	push1(val);
	count++;
	printf("\n Do you want to  continue{5|6} ");
	scanf("%d",&v);
   }while(v==5);
   
}


void display_link()
{
    struct node *ptr;
    ptr=head;
    if(head==NULL && tail==NULL)
    {
        printf("\n Empty queue.");
        
    }
    else
    {   printf("\nQUEUE");
        do
        {
            printf("\t%d",ptr->data);
            ptr=ptr->next;
        }while(ptr!=head);
    }
    
}

int peek_link()
{
    if(head==NULL)
    {
        printf("\n Empty queue.");
        return -1;
    }
    else
    {
        printf("\nThe topest number of the queue=%d",head->data);
        
    }
}

void del_link()
{
 // printf("\n %d",tail->data);
   struct node *ptr;
   ptr=head;
   if(head==NULL && tail==NULL)
    {
        printf("\n STACK UNDERFLOW.");
    }
    else if(head==tail)
    {
    	head=tail=NULL;
    	free(ptr);
	}
	else
    {
      head=head->next;
      tail->next=head;
      printf("The value deleted from thr queue is=%d",ptr->data);
      free(ptr);
    }
  
}

void ins_link()
{
    struct node *new_node;
    int val,x;
    do
    {
    printf("\nEnter the number to be pushed on queue:");
    scanf("%d",&val);
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=val;
    if(head==NULL && tail==NULL)
    {
       head=tail=new_node;
        tail->next=head;
    }
    else
    {
    	tail->next=new_node;
        new_node->next=head;
        tail=new_node;
    }
    printf("\n Do you want to continue{5|6}:");
    scanf("%d",&x);
    }while(x==5);
    
}


void display_que(int st[])
{
   	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("\n Queue is Empty.");
	}
	else
	{
		printf("\n QUEUE:");
		while(i!=rear)
		{
			printf("\t%d{%d}",st[i],i);
			i=(i+1)%max;
		}
		printf("\t%d{%d}",st[rear],rear);
    }
}

void peek_que(int st[])
{
	if(front==-1 && rear==-1)
	{
		printf("\n Queue is Empty.");
	}
	else
	{
		printf("\n The front number at the queue is %d",st[front]);
	}
}

void del_que(int st[])
{
	
	if(front==-1)
	{
		printf("\n UNDERFLOW.");
	}else
	if(front==rear)
	{
		printf("n The deleted number from the queue is %d",st[front]);
		front=rear=-1;
	}
	else
	{
		printf("n The deleted number from the queue is %d",st[front]);
		front=(front+1)%max;
	}
}

void ins_que(int st[])
{
	int val,x;
	do
	{
	printf("\nEnter the number to be inserted in the queue:");
    scanf("%d",&val);
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		st[rear]=val;
	}
	else 
	if((rear+1)%max==front)
	{
		printf("\n OVERFLOW.");
	}
	else
	{
		rear=(rear+1)%max;
		st[rear]=val;
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
    printf("\n 1.circuler queue using array.");
    printf("\n 2.circuler queue using linkedlist.");
    printf("\n 3.Queue useing stacks.");
    printf("\n 4.Deque.");
    printf("\n 5.Priority Queue(sorted)using Linkedlist.");
    printf("\n 6. End of the program.");
    printf("\n********************************************\n");
    printf("\n Enter the option:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
             while(1)
             {
                printf("\n*************QUEUE_ARRAY********************\n");
                printf("\n 1.insert.");
                printf("\n 2.delete.");
                printf("\n 3.peek.");
                printf("\n 4.display.");
                printf("\n 5.Goto main menu");
                printf("\n********************************************\n");
                printf("\n Enter the option:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1: ins_que(st);
                            break;
                    case 2: del_que(st);
                            break;
                    case 3:peek_que(st);
                            break;
                    case 4:display_que(st);
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
                printf("\n 1.Insert.");
                printf("\n 2.Delete.");
                printf("\n 3.peek.");
                printf("\n 4.display.");
                printf("\n 5.Goto main menu");
                printf("\n********************************************\n");
                printf("\n Enter the option:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1: ins_link();
                            break;
                    case 2: del_link();
                            break;
                    case 3:peek_link();
                            break;
                    case 4: display_link();
                            break;
                    case 5: goto back;
                            break;
                    
                }
             }break;
              case 3: 
             while(1)
             {
                printf("\n*************QUEUE_ARRAY********************\n");
                printf("\n 1.insert.");
                printf("\n 2.delete.");
                printf("\n 3.peek.");
                printf("\n 4.display.");
                printf("\n 5.Goto main menu");
                printf("\n********************************************\n");
                printf("\n Enter the option:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1: enqueue();
                            break;
                    case 2: dequeue();
                            break;
                    case 3:peek__que();
                            break;
                    case 4:display__que();
                            break;
                    case 5: goto back;
                            break;
                    
                }
            }
             
             break;
             case 4: 
             while(1)
             {
                printf("\n*************DEQUE_ARRAY********************\n");
                printf("\n 1.insert at front with anticlockwise.");
                printf("\n 2.delete at front with clockwise.");
                printf("\n 3.insert at rear with clockwise.");
                printf("\n 4.delete at rear with anticlockwise.");
                printf("\n 5.display.");
                printf("\n 6.front number.");
                printf("\n 7.rear number.");
                printf("\n 8.Goto main menu.");
                printf("\n********************************************\n");
                printf("\n Enter the option:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1: ins_front();
                            break;
                    case 2: del_front();
                            break;
                    case 3: ins_rear();
                            break;
                    case 4: del_rear();
                            break;
                    case 5: display();
                            break;
                    case 6: getfront();
                            break;
                    case 7: getrear();
                            break;
                    case 8: goto back;
                            break;
                    
                }
            }
             
             break;
             case 5: 
             while(1)
             {
                printf("\n*************priority queue_linkedlist********************\n");
                printf("\n 1.insert.");
                printf("\n 2.delete.");
               // printf("\n 3.peek.");
                printf("\n 4.display.");
                printf("\n 5.Goto main menu");
                printf("\n********************************************\n");
                printf("\n Enter the option:");
                scanf("%d",&ch);
                switch(ch)
                {
                    case 1: ins_pque();
                            break;
                    case 2: del_pque();
                            break;
                    
                    case 4:display_pque();
                            break;
                    case 5: goto back;
                            break;
                    
                }
            }
             
             break;
             case 6:
             	exit(0);
             	break;
         }
     }
 }
