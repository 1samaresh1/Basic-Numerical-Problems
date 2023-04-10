	#include<iostream>
	#include<math.h>
	#define pi 3.14
	using namespace std;
	
	int main()
	{
		 	
		int arr[5]={15,15,30,45,50};
		 for(int i=0;i<5;i++)
		 {
		   for(int j=i+1;j<5;j++)
		 	{
		 		if(arr[i]>arr[j])
		 		{
		 			float temp=arr[i];
		 			 
		 			 arr[i]=arr[j];
		 			 arr[j]=temp;
				 }
			 }
		 }
		for(int i=0;i<5;i++)
		{
			cout<<arr[i]<< " ";
		}
		int GCD;
   for( GCD =arr[0]; GCD >= 1; GCD--)
	{
	// GCD is the greatest number that divides both the numbers
	if(arr[0]%GCD == 0 && arr[1]%GCD == 0 && arr[2]%GCD == 0 && arr[3]%GCD == 0 && arr[4]%GCD == 0)
	break; // exits the loop
	}
	    cout<< GCD;
		return 0;
	}
