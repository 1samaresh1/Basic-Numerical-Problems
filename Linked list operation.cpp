#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
 struct node *create(struct node *);
 struct node *create1(struct node *);
 struct node *insert_beg(struct node *);
 struct node *insert_end(struct node *);
 struct node *insert_aft(struct node *);
 struct node *insert_bef(struct node *);
 struct node *insert_nthpos(struct node *);
 struct node *delete_beg(struct node *);
 struct node *delete_end(struct node *);
 struct node *delete_node(struct node *);
 struct node *display(struct node *);
 struct node *sort(struct node *);
 struct node *reverse(struct node *);
 struct node *search(struct node *);
 struct node *concat(struct node *,struct node *);



 int main()
{ 
	struct node *start = NULL;
	struct node *start1 = NULL;
	int ch;
	while(1)
	{
		printf("\n\n*******___ALL MENU____*******");
		printf("\n =====================================");
		printf("\n 1: Create list");
		printf("\n 2: Insert a node at the begining");
		printf("\n 3: Insert a node at the end");
		printf("\n 4: Insert after a node");
		printf("\n 5: Insert before a node");
		printf("\n 6: Insert a node at nth position");
		printf("\n 7: Delete a node from the begining");
		printf("\n 8: Delete a node from the end");
		printf("\n 9: Delete a given node ");
		printf("\n 10: Display the list");
		printf("\n 11: sorting the linked list");
		printf("\n 12: Reverse order to display the list");
		printf("\n 13: Another create list");
		printf("\n 14: node searching");
		printf("\n 15: concatenation");
		printf("\n 16:End of the program");
		printf("\n =====================================");
		printf("\n\t: Enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			 case 1:
				 start = create(start);
				 break;
		         case 2: start = insert_beg(start);
				 start = display(start);
				break;
		         case 3: start = insert_end(start);
				 start = display(start);
				break;
		         case 4: start = insert_aft(start);
				 start = display(start);
				break;
                         case 5: start = insert_bef(start);
				 start = display(start);
				break;
		         case 6: start = insert_nthpos(start);
				 start = display(start);
				break;
			 case 7: start = delete_beg(start);
				 start = display(start);
				break;
			 case 8: start = delete_end(start);
				 start = display(start);
				break;
			 case 9: start = delete_node(start);
				 start = display(start);
				break;
			 case 10: start = display(start);
				 break;
		         case 11:start = display(start);
				  start = sort(start);
				 printf("\n");
				  start = display(start);
				 break;
	                 case 12: start = display(start);
				  start = reverse(start);
				  printf("\n");
				  start = display(start);
				 break;
		         case 13: start1 = create(start1);
				 break;
			 case 14: start = search(start);
				 break;
			 case 15:
				 start = concat(start,start1);
				  start = display(start);
				break;  
		         case 16: exit(0);
		          default: 
				 printf("Your Enter choice is wrong");
		}
	}
}

	struct node *create(struct node *start)
	{
		struct node *new_node , *p;
		start = NULL;
		int numb,count=0;
		int ch;
	                do
	                 {
	                   new_node = (struct node *)malloc(sizeof(struct node));
	        	   printf("\n Enter the data:");
	                   scanf("%d",&numb);
	                   new_node -> data = numb;
			   new_node -> next = NULL;
		         if( start == NULL)
	                  { 
			    start = new_node;
			    p = start;
		           }
		         else
		           {
			     p -> next = new_node;
			     p = p -> next;
			
		            }
		
		            printf(" Do you want to create a another node?[5|9]:");
	                    scanf("%d",&ch);
			    while(ch != 5 && ch != 9)
		             {	
				printf("\n you enter wrong key.   press the right key.....");
				fflush(stdin);
				scanf("%d",&ch);
		        	}

	        	 } while(ch ==5);

		              p = start;
			      printf("\nThe list:");
			      while(p != NULL)
			       {
				       count = count+1;
				   printf("[%d]\t",p -> data);
				       p = p -> next;
			       }
			           printf("\nNumber of node-%d\n",count);
			      return start;
	          }
           

 
/*	struct node *create(struct node *start1)
        {

		struct node *new_node , *p;
		start1 = NULL;
		int numb,ch,count;
		count=0;
	         do
		 {

	           new_node = (struct node *)malloc(sizeof(struct node));
	        	printf("\n Enter the data:");
	                scanf("%d",&numb);
	                 new_node -> data = numb;
			 new_node -> next = NULL;
			 if (start1 == NULL)
			 {
				 start1 = new_node;
				 p = start1;
			 }
			   else
			      {
				      p -> next = new_node;
			              start1 = new_node;
			      }
		           printf(" Do you want to create  another a node?? [5|9]:");
			   scanf("%d",&ch);
		 } while(ch == 5);

		      p = start1;
		      printf(" Another list:");
                      while(p != NULL)
		      {
			      count = count+1;
			      printf("\n[%i]\t",p ->data);
			      p = p ->next;
		      }
		      printf("\n Numbers of node-%d\n",count);
	           return start1;
	}
*/

	struct node *insert_beg(struct node *start)
	
	{
		struct node *new_node;
		int numb;
		printf("\n Enter the data:");
	        scanf("%d",&numb);
	        new_node = (struct node *)malloc(sizeof(struct node));
                new_node -> data = numb;
		new_node -> next = start;
		start = new_node;
		return start;
	}

	struct node *insert_end(struct node *start)
	{
		struct node *new_node, *p;
		int numb;
		printf(" Enter the data:");
		scanf("%d",&numb);
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node -> data = numb;
		new_node -> next = NULL;
		p = start;
		while(p -> next != NULL)
		{
			p = p -> next;
		}
		    p -> next = new_node;

		    return start;
	
	}

	struct node *insert_aft(struct node *start)
	{
		struct node *new_node , *p ,*prep;                              // prep = another pointer node (previous pointer)
	       int numb,val;
	       printf("\n Enter the data:");
	       scanf("%d",&numb);
	       printf("\n Enter the value after inserted:");
	       scanf("%d",&val);
	       new_node = (struct node *)malloc(sizeof(struct node));
	       new_node -> data = numb;
	       p = start;
	       prep = p;
	       while(prep -> data != val)
                  {
			  prep = p;
			  p = p -> next;
		  }
	             prep -> next = new_node;
		     new_node -> next = p;
		     return start;


	}

	struct node *insert_bef(struct node *start)
	{
		struct node *new_node , *p , *prep;
	       int numb,val;
	       printf("\n Enter the data:");
	       scanf("%d",&numb);
	       printf("\n Enter the value before inserted:");
	       scanf("%d",&val);
	       new_node = (struct node *)malloc(sizeof(struct node));
	       new_node -> data = numb;
	       p = start;
	       while(p -> data != val)
               {
		       prep = p;
		       p = p -> next;
	       }
	             
	             prep -> next = new_node;
		     new_node -> next = p;
		     return start;
	}

	struct node *insert_nthpos(struct node *start)
          {
		  struct node *new_node, *p;
		  int numb,position;
		  int i;
		  printf("\n Enter the data:");
                  scanf("%d",&numb);
		  printf("\n Enter the position-");
		  scanf("%d",&position);
		  new_node = (struct node *)malloc(sizeof(struct node));
		  new_node -> data = numb;
		  if(position ==1)
		  {
			  new_node -> next = start;
			  start = new_node;
			  return start;
		  }
		  p = start;
		  for(i=1;i<position-1 && p!= NULL; i++)
                   {
			   p = p ->next;
		   }
		          new_node -> next = p -> next;
			  p -> next = new_node;

		        if(p == NULL)
			{
				printf("The enter position %d is wrong.",position);
			} 
			    return start;
	  }

         struct node *delete_beg(struct node *start)
	 {
		 struct node *p;
		 p = start;
		 start = p -> next;
		 free(p);
		 return start;
	 }
	 
         struct node *delete_end(struct node *start)
	 {
		 struct node *p , *prep;
		 p = start;
		 while(p -> next != NULL)
		 {
			 prep = p;
			 p = p -> next;
		 } 
		   if(p == start)
		   {
			   start = NULL;
			   free(p);
		   } 
		   else
		   {
		        prep -> next = NULL;
			free(p);
		   }
			return start;
	 }

           struct node *delete_node(struct node *start)
	   {
		   struct node *p , *prep;
		   int val;
		   printf("\n Enter the value of node data which has to be delete:");
		   scanf("%d",&val);
		   p = start;
                   if(p -> data == val)
		   {
			   start = delete_beg(start);
			   return start;
		   }
		     else
		     { 
			     while(p ->data != val)
			     {
				     prep = p;
				     p = p ->next;
			     }
			          prep -> next = p -> next;
				  free(p);
				  return start;
		     }
	   }
          
	   struct node *display(struct node *start)
	   { 
	      struct node *p;
	      int count;
	      count = 0;
		      p = start;
		      printf("The list:");
		      while(p != NULL)
		      {
			      count = count+1;
			      printf( "[%d]\t",p -> data);
			      p = p -> next;
		        }
		              printf("\n The number of nodes is %d",count);
		              return start;
	   }


           struct node *sort(struct node *start)
	   {
		   struct node *p1 ,*p2;
		   int tamp;
		   p1 = start;
		   while(p1 ->next != NULL)
		   {
			   p2 = p1 ->next;
			   while(p2 != NULL)
			   {
				   if(p1 ->data > p2 ->data)
			        	{
						tamp = p1 ->data;
						p1 ->data = p2 ->data;
						p2 ->data = tamp;
					}
				   p2 = p2 -> next;
			   }
			       p1 = p1 -> next;
		   }
		       return start;
	   }
	   struct node *reverse(struct node *start)
	   {
		   struct node *pp , *cp , *np;
		   pp = NULL;
		   cp = np =start;
		   while(np != NULL)
		   {
			   np = np -> next;
			   cp -> next = pp;
			   pp = cp;
			   cp = np;
		   }
		          start = pp;
			  return start;
	   }
          
	struct node *search(struct node *start)
         {
		 struct node *p;
		int val,pos=0,sam=0;
		printf("\n Enter the searching value:");
	       scanf("%d",&val);
               p = start;
              while(p != NULL)
	      { 
		      pos=pos+1;
		  if(val == p -> data)
		  {
			  sam = 1;
			  break;
	          } 
		  p = p -> next;
	      }
	      if(sam ==1)
	      { 
		      printf("The value is found and position is %d",pos);
	      }
	         else
		 {
			 printf(" The value is not found");
		 }
                   return start;
	 }
	
	
	    struct node *concat(struct node *start, struct node *start1)
             {
		     struct node *p;
		     p = start;
		     while(p -> next != NULL)
		     {
			     p = p ->next;
		     }
		        p -> next = start1;
			
			return start;

	     }     		 
