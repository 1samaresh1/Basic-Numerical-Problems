	#include<iostream>
	#include<math.h>
	#define pi 3.14
	using namespace std;
	
	int main()
	{
		int i;
		int j;
		for( i=8;i>=-8;i--)  //x-axis
		{
		   for( j=0;j<=68;j++)  // y-axis
		   {
		   	 if(i*i==j)
		   	 {
		   	 	cout<<"*";
		   	 	cout<<endl;	
		   	 	break;
		   	 }else
				{
					cout<<" ";
				}
			}
			
		}
		
		return 0;
	}
