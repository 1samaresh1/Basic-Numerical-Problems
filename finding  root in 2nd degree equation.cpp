#include<math.h>
#include<stdio.h>
int main()
{
	float a,b,c,r1,r2,r,d;
	printf("Enter the three numbers a,b,and c:\n");
	scanf("%f%f%f",&a,&b,&c);
	if(a==0.0)
	{
		printf("The equation is linear\n");
		r=-(c/b);
		printf("The root is %f\n",r);
	}
	else{
   d=(b*b-4.0*a*c);
   if(d>0)
   {
   	 printf("roots are real and distinct\n");
   	 r1=(-b+sqrt(d))/(2.0*a);
   	 r2=(-b+sqrt(d))/(2.0*a);
   	 printf("Root1=%f and Root2=%f",r1,r2);
   }
   if(d<0)
   {
   	printf("root are imaginiry\n");
   }
   if(d==0)
   {
   	printf("roots are equal\n");
   	r=(-b/(2.0*a));
   	printf("Roots are : %f and %f",r,r);
   }
	}
	return 0;
}
