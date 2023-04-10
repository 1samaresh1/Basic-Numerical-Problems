#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
void read(void);
void display(int a[],int n);
void lin_ser(int a[],int n);
void bin_serwor(int a[],int n);
void bin_serwr(int a[],int n);
int subfunwr(int a[],int val,int lef,int rig);
int subfunwor(int a[],int val,int lef,int rig);
void ins_sort(int a[],int n); 
void bub_sort(int a[],int n);
void sel_sort(int a[],int n);
void mer_sort(int a[],int lb, int ub);
void quick_sort(int a[],int lb, int ub);
int partitions(int a[],int lb, int ub);
void submarg(int a[],int lb, int mid, int ub);
//void hep_sort(int a[],int n);
int ch,n,a[15];
int main() 
{ 
	//int ch,n,a[15];
       while(1)
	{
	  printf("\n*************MAIN MENU************");
	  printf("\n===================================");
	  printf("\n1.Sorting");
	  printf("\n2.Searching");
	  printf("\n3.End of the program");
	  printf("\n=================================");
	  printf("\n\tEnter the choice:");
	  scanf("%d",&ch);
	  switch(ch)
	    {
             case 1:while(1)
	             {    
                         printf("\n----------------------------");
			 printf("\n1.Bubble sort");
			 printf("\n2.Selection sort");
			 printf("\n3.Insertion sort");
		         printf("\n4.Quick sort");
		         printf("\n5.Merge sort");
			 printf("\n6.Heap sort");
		         printf("\n7.Exit of this loop");
		         printf("\n---------------------------");
		         printf("\n\t Enter the choice:");
	                 scanf("%d",&ch);
		         switch(ch)
			     {
	                        case 1:read();
				      display(a,n);
				      bub_sort(a,n);
				      break;
		                case 2: read();
				       	display(a,n);
				        sel_sort(a,n); 
					break;
			        case 3:read();
				       display(a,n);
				       ins_sort(a,n);
				       break;
			        case 4:read();
				       display(a,n);
				       quick_sort(a,0,n-1);
				       display(a,n);
			               break;
			        case 5:read();
				      display(a,n);
				      mer_sort(a,0,n-1);
				      display(a,n);
				      break;
			        case 6: display(a,n);
				      //hep_sort(a,n); 
			              printf("\n After sorting ");
				      display(a,n);
				      break;
			        case 7: exit(0);
					    	break;
			                
				}
		    }break;
			        
				

		
                    case 2: while(1)
			         
			         {
						 	int i;
			         	printf("\n How many elements do you want to add in the array:");
			         	scanf("%d",&n);
			         	for(i=0;i<n;i++)
			         	{
			         		printf("\n arr[%d]=",i);
			         		scanf("%d",&a[i]);
						 }
					
						 while(1)
                          {
									
				        	printf("\n----------------------------------------------");
				        	printf("\n1.Linear Searching");
				        	printf("\n2.Binary Searching using Recursion");
				        	printf("\n3.Binary Searching using whitout Recursion");
				         	printf("\n4.Exit of the loop");
				        	printf("\n---------------------------------------------");
				        	printf("\n\t Enter the choice:");
			            	scanf("%d",&ch);
					switch(ch)
				    	{
						case 1: display(a,n);
					         	lin_ser(a,n);
						        break;
						case 2:display(a,n);
						        bin_serwr(a,n);
						        break;
						case 3: display(a,n);
						        bin_serwor(a,n);
				            	break;
					    case 4: exit(0);
					            break;
			        	}
					
				       } break;
	            	} 
    	}
 }
}


void display(int a[15],int n)
     {
	int i;
	printf("\n The array elements are:");
	for(i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
	
     }

void lin_ser(int a[15],int n)
      {
         int i,val;
	 int sum=0,ram =-1;
	 printf("\nEnter the element that need to be searched:");
	 scanf("%d",&val);
	 for(i=0;i<n;i++)
	{       //sum = sum +1;
		if(a[i]==val)
		{
			ram = 1;
			break;
		//	index =i;
			
		}
	}
	if(ram == 1)
	{ 
		printf("\n Enter the element to be needs and position/index is %d",i);

	//	printf("\n The worst case time complexity order of n is-%d",sum);
		printf("\n");
	}
       	else
	{
		printf("\n The element is not found");
		//printf("\n The worst case time complexity order of n is-%d",sum);
		printf("\n");
	}
	return;
    }
 
		 
 void bin_serwor(int a[15],int n)
    {
	      int val,r;
	   
        printf("\nEnter the element that need to be searched:");
	     scanf("%d",&val);
	      r=subfunwor(a,val,0,n-1);
	      if(r==-1)
		    {
		    printf("\n Enter the element is not found");
		//	printf("\n The worst case time complexity order of n is-%d",sum);
		    printf("\n");	
			}
				else
	               {
		            printf("\n The element is  found and index is %d",r);
		            //printf("\n The worst case time complexity order of n is-%d",sum);
	                	printf("\n");
                	}
					return;
		 
	}
		 
 void bin_serwr(int a[15],int n)
    {
	    int val,r;
	   
        printf("\nEnter the element that need to be searched:");
	     scanf("%d",&val);
	      r=subfunwr(a,val,0,n-1);
	      if(r==-1)
		    {
		    printf("\n Enter the element is not found");
		//	printf("\n The worst case time complexity order of n is-%d",sum);
		    printf("\n");	
			}
				else
	               {
		            printf("\n The element is  found and index is %d",r);
		            //printf("\n The worst case time complexity order of n is-%d",sum);
	                	printf("\n");
                	}
					return;
	}
	
int subfunwr(int a[15],int val,int lef,int rig)
   {
   
	   int mid;
	    mid=(lef+rig)/2;
	     if(lef<=rig)
	     
		   if(val==a[mid])
	        {
	     	  return mid;
		    }
		    else 
			  if(val<a[mid])
			   return subfunwr( a, val,lef,mid-1);
	     	   else
		          return subfunwr( a,val,mid+1,rig);
	        
	     
		   return -1;
}
		 
int subfunwor(int a[15],int val,int lef,int rig)
   {
   
	   int mid;
	    while(lef<=rig)
	     {  mid=(lef+rig)/2;
		   if(val==a[mid])
	        {
	     	  return mid;
		    }
		    else 
			  {
			    if(val<a[mid])
			     rig=mid-1;
	     	   else
	     	     lef=mid+1;
		      }
	      }
	     
		   return -1;
}	 
		 
void bub_sort(int a[15],int n)
{
   int i,j,temp,flog;
   for(i=0;i<n-1;i++)
      {
        flog=0;
         for(j=0;j<n-1-i;j++)
	{
	 if(a[j]>a[j+1])
          {	
	     temp=a[j];
	     a[j]=a[j+1];
	     a[j+1]=temp;
	     flog =1;
	  }
        }
	    if(flog==0)
            break;
      }
        display(a,n);
}
		 
void ins_sort(int a[15],int n)
{
	int i,j,temp;
	 for(i=1;i<n;i++)
	 {
	 	temp=a[i];
	 	j=i-1;
	 	while(j>=0 && a[j]>temp)
	 	{
	 		a[j+1]=a[j];
	 		j--;
		   a[j+1]=temp;
	     }
	 }
       display(a,n);	 
}		 
		 
void sel_sort(int a[15],int n)
{
	int i,j,min,pos;
	  for(i=0;i<n-1;i++)
	  {
	  	pos = i;
	  	min= a[i];
	  	for(j=i+1;j<n;j++)
	  	 {
	  	 	if(a[j]<min)
	  	 	 { 
	  	 	 min = a[j];
	  	 	 pos =j;
			 }
		}
			a[pos]=	a[i];
			a[i]= min;
		   
	  }
	   display(a,n);
 }		 
		 
void quick_sort(int a[15],int lb, int ub)
{
	int sam;
	if(lb<ub)
	{
		sam= partitions(a,lb,ub);
		quick_sort(a,lb,sam-1);
		quick_sort(a,sam+1,ub);
		// display(a,n);
	}
	//display(a,n);
}

int partitions(int a[15],int lb, int ub)
{
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	int temp;
	while(start<end)
	{
		while(a[start]<=pivot)
		    start++;
		while(a[end]>pivot)
		    end--;
		 if(start<end)
		 {
		 	temp=a[start];
			 a[start]=a[end];
			 a[end]=temp;
		 }
	}
	 temp=a[lb];
	 a[lb]=a[end];
	 a[end]=temp;
	return end;
}
void mer_sort(int a[15],int lb, int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		mer_sort(a,lb,mid);
		mer_sort(a,mid+1,ub);
		submarg(a,lb,mid,ub);
		//display(a,n);
	}
//	display(a,n);
}
void submarg(int a[15],int lb, int mid, int ub)
{
     int i,j,k;
     int b[15];
	 i=lb;
	 j=mid+1;
	 k=lb;
	 while(i<=mid && j<=ub)
	 {
	   if(a[i]<=a[j])
	   {
	   	b[k]=a[i];
	   	i++;
	   }
	   else
	   {
	   	b[k]=a[j];
	   	j++;
		}
		k++;	
	 }
	 if(i>mid)
	 {
	 	while(j<=ub)
	 	{
	 		b[k]=a[j];
	 		j++;
	 		k++;
		 }
	}
		     else
		     {
		    	while(i<=mid)
		     	{
		 		b[k]=a[i];
		 		i++;
		 		k++;
			    }
		     }
	    for(k=lb;k<=ub;k++)
		 {
		 	a[k]=b[k];
		 }
		 
	}
	 	
 void  read()
  {
      int i;
      printf("\n How many elements do you want to add in the array:");
	  scanf("%d",&n);
	   for(i=0;i<n;i++)
    	{
	        printf("\n arr[%d]=",i);
			scanf("%d",&a[i]);
	    }
	 }	
		 
	
