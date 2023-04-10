	#include<iostream>
	#include<math.h>
	#define pi 3.14
	using namespace std;
	
	int main()
	{
		 int arr[5]={4,5,16,30,6};
		 int s0,s1,s2,s3,s4,lcm=1, i=2;
		 s0=s1=s2=s3=s4=1;
		while(i)
		{
	      if(arr[0]%i==0||arr[1]%i==0||arr[2]%i==0||arr[3]%i==0||arr[4]%i==0)
	      {
	      	 lcm=i*lcm;
		  }
	     if(arr[0]%i==0)
		 {
		 	arr[0]=arr[0]/i;
		 	s0=0;
		 }
		if(arr[1]%i==0)
		 {
		 	arr[1]=arr[1]/i;
		 	s1=0;
		 }
		if(arr[2]%i==0)
		 {
		 	arr[2]=arr[2]/i;
		 	s2=0;
		 }
		if(arr[3]%i==0)
		 {
		 	arr[3]=arr[3]/i;
		 	s3=0;
		 }
		 if(arr[4]%i==0)
		 {
		 	arr[4]=arr[4]/i;
		 	s4=0;
		 }
		 
		  if(arr[0]==1 && arr[1]==1&& arr[2]==1&& arr[3]==1&& arr[4]==1)
		  {
		  	break;
		  }
		  i=i+(s0+s1+s2+s3+s4)/5;
		  s0=s1=s2=s3=s4=1;
		}
	
		cout<<"lcm="<<lcm; 
		  
		return 0;
	}

