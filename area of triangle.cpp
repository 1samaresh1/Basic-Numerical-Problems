#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c;
	float s,area;
	printf("Enter the three numbers:");
	scanf("%d\n%d\n%d",&a,&b,&c);
	s=(float)((a+b+c)/2.0);
	area=sqrt(s*(s-a)*(s-b)*(s-c));
	printf("the value is %5.2f %8.5f",s,area);
	return 0;
}
