/* **********************************************************************************************
                    Samaresh Patra(MCA 1st semester)
***************************************************************************************************/					
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
   int powx,coffx;
   struct node *next;
};
struct node *head=NULL;
struct node *head1=NULL;
struct node *head2=NULL;
struct node *head3=NULL;
struct node *head4=NULL;
struct node *create_pol(struct node *);
struct node *display(struct node *);
struct node *add(struct node *,struct node *,struct node *);
struct node *sub(struct node *,struct node *,struct node *);
struct node *mul(struct node *,struct node *,struct node *);
struct node *add_nodes(struct node *,int,int);
struct node *simplifymul(struct node *);

struct node *mul(struct node *head,struct node *head1,struct node *head4)
{
	 struct node *ptr,*ptr1;
    ptr=head;
    //ptr1=head1;
    int sum,mul;
    while(ptr!=NULL)
    {
    	ptr1=head1;
    	while(ptr1!=NULL)
    	{
    		mul=(ptr->coffx * ptr1->coffx);
    		sum=(ptr->powx +ptr1->powx);
    		head4=add_nodes(head4,mul,sum);
    		ptr1=ptr1->next;
		}
		 ptr=ptr->next;
	}
	return head4;
}
struct node *simplifymul(struct node *head)
{  
   struct node *ptr,*nptr,*pptr,*temp;
   ptr=head;
   int sum=0;
	while(ptr!=NULL)
    {   pptr=ptr;
	   nptr=ptr->next;
	   sum=ptr->coffx;
       while(nptr!=NULL)
        {  
	       if(ptr->powx==nptr->powx)
	          {
			    sum=(nptr->coffx + sum);
			    pptr->next=nptr->next;
			    temp=nptr;
			    nptr=nptr->next;
			    ptr->coffx=sum;
			    free(temp);
              }
              else
              {
               pptr=nptr;
	           nptr=nptr->next;
	         }
	      }
        
	   ptr=ptr->next;
     }
	return head;
}

struct node *sub(struct node *head,struct node *head1,struct node *head3)
{
	 struct node *ptr,*ptr1;
    ptr=head;
    ptr1=head1;
    int sub,s;
    
    while(ptr!=NULL && ptr1!=NULL)
    {
        if(ptr->powx==ptr1->powx)
        {
            sub=ptr->coffx - ptr1->coffx;
            head3=add_nodes(head3,sub,ptr->powx);
            ptr=ptr->next;
            ptr1=ptr1->next;
        }
        else if(ptr->powx<ptr1->powx)
        {
        	s=-(ptr1->coffx);
         head3=add_nodes(head3,s,ptr1->powx);
         ptr1=ptr1->next;
        }
        else if(ptr->powx>ptr1->powx)
        {
           head3=add_nodes(head3,ptr->coffx,ptr->powx); 
           ptr=ptr->next;
        }
    }
    if(ptr==NULL)
    {
        while(ptr1!=NULL)
        {
        	s=-(ptr1->coffx);
         head3=add_nodes(head3,s,ptr1->powx);
         ptr1=ptr1->next; 
        }
    }
    
     if(ptr1==NULL)
    {
        while(ptr!=NULL)
        {
         head3=add_nodes(head3,ptr->coffx,ptr->powx);
         ptr=ptr->next; 
        }
    }
    
    return head3;
}

struct node *add_nodes(struct node *heads,int co,int po)
{
     struct node *new_node,*ptr;
    new_node=(struct node *)malloc(sizeof(struct node));
    if(heads==NULL)
    {
    new_node->powx=po;
    new_node->coffx=co;
    new_node->next=NULL;
    heads=ptr=new_node;
    }
    else
    {
        ptr=heads;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        new_node->powx=po;
        new_node->coffx=co;
        new_node->next=NULL;
        ptr->next=new_node;
    }
    return heads;
}

struct node *add(struct node *head,struct node *head1,struct node *head2)
{
    struct node *ptr,*ptr1;
    ptr=head;
    ptr1=head1;
    int sum;
    
    while(ptr!=NULL && ptr1!=NULL)
    {
        if(ptr->powx==ptr1->powx)
        {
            sum=ptr->coffx + ptr1->coffx;
            head2=add_nodes(head2,sum,ptr->powx);
            ptr=ptr->next;
            ptr1=ptr1->next;
        }
        else if(ptr->powx<ptr1->powx)
        {
         head2=add_nodes(head2,ptr1->coffx,ptr1->powx);
         ptr1=ptr1->next;
        }
        else if(ptr->powx>ptr1->powx)
        {
           head2=add_nodes(head2,ptr->coffx,ptr->powx); 
           ptr=ptr->next;
        }
    }
    if(ptr==NULL)
    {
        while(ptr1!=NULL)
        {
         head2=add_nodes(head2,ptr1->coffx,ptr1->powx);
         ptr1=ptr1->next; 
        }
    }
    
     if(ptr1==NULL)
    {
        while(ptr!=NULL)
        {
         head2=add_nodes(head2,ptr->coffx,ptr->powx);
         ptr=ptr->next; 
        }
    }
    
    return head2;
}

struct node *display(struct node *head)
{
    struct node *ptr;
    ptr=head;
   
    printf(" polynomial:");
    while(ptr!=NULL)
    {
       printf("\t%dX^%d",ptr->coffx,ptr->powx);
       ptr=ptr->next;
    }
    return head;
}

struct node *create_pol(struct node *head)
{
    struct node *new_node,*ptr;
    int p,c,ch;
    do
    {
    printf("\n Enter the power of x and it cofficient:");
    scanf("%d",&p);
    scanf("%d",&c);
    new_node=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
    new_node->powx=p;
    new_node->coffx=c;
    new_node->next=NULL;
    head=ptr=new_node;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        new_node->powx=p;
        new_node->coffx=c;
        new_node->next=NULL;
        ptr->next=new_node;
    }
    printf("\nDo you want to continue then press 1");
    scanf("%d",&ch);
   }while(ch==1);
   
    return head;
}
int main()
{
    int ch;
    while(12)
    {
    printf("\n\n******************MAIN MANU**************\n");
    printf("\n1.Enter the first polynomial.");
    printf("\n2.Enter the second polynomial.");
    printf("\n3.Addition of two polynomials.");  
    printf("\n4.Substruction of two polynomials.");
    printf("\n5.Multipication of two polynomials.");
    printf("\n6.Divide by one anther polynomials.");
    printf("\n7.End of the program.");
    printf("\n*******************************************\n");
    printf("\nEnter the option:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: head=create_pol(head);
                printf("\nFirst ");
		        head=display(head);
		            break;
	    case 2: head1=create_pol(head1);
	            printf("\nSecond ");
		        head1=display(head1);
		            break;
    	case 3: head2=add(head,head1,head2);
                printf("\nAfter Adding");
		        head2=display(head2);
		            break;
    	case 4: head3=sub(head,head1,head3);
                printf("\nAfter Substruction");
		        head3=display(head3);
		            break;
	    case 5: head4=mul(head,head1,head4);
	            head=simplifymul(head4);
                printf("\nAfter Multiplication");
		        head=display(head);
		            break;
		case 7: exit(0);
    }
  }
    
}
