#include<stdio.h>
#include<stdlib.h>
int prime(void);
int sum_digit(void);
int greatest_val(void);
int fact_val(void);
int bel_tringle(void);
int upto_nthprime(void);
int fib_serise(void);
int sum_serise(void);
int main()
   {
     int ch;
     while(1)
       {
	       printf("\n __________ALL MINU__________");
	       printf("\n===============================");
	       printf("\n 1.check prime or composite");
	       printf("\n 2.Sum of all digite in the integer number");
	       printf("\n 3.Find the Greatest numbers");
	       printf("\n 4.Find Factorial value of the number");
	       printf("\n 5.Below Floyd's tringle");
	       printf("\n 6.Find the all prime numbers upto n");
	       printf("\n 7.Find the fibonacci serise");
	       printf("\n 8.summation i/i! from i=1 to n");
	       printf("\n 9.End of the progrem");
	       printf("\n===============================");
	       printf("\n Enter the choice:");
	       scanf("%d",&ch);
	       switch(ch)
                {
			case 1: prime();
				break;
			case 2: sum_digit();
				break;
			case 3: greatest_val();
				break;
			case 4: fact_val();
				break;
			case 5: bel_tringle();
				break;
			case 6: upto_nthprime();
				break;
			case 7: fib_serise();
				break;
			case 8: sum_serise();
				break;
		        case 9: exit(0);
				break;
		}
       }  
   }



int prime()
{
    int p,i,sam=0;
    printf("Enter a number:");
	scanf("%d",&p);
        for(i=2;i<p;i++)
	{ 
		if(p%i ==0)
		  sam =1;	
		   break;
		
	}
		if(sam ==1)
		{
			printf("\n %d is a composite number",p);
		} else
			printf("\n%d is a prime number",p);
		return 0;

}
        
  int sum_digit()
{
	int n,m,sum=0;
	printf("\n Enter the value:");
	scanf("%d",&n);
	while(n != 0)
	{
		m = n%10;
		sum = sum+m;
		n = n/10;
	}
	printf("The sum value of all digitis is %d",sum);
	return 0;
}

int greatest_val()
{
	int a,b,c;
	printf("Enter three value:");
	scanf("%d\n%d\n%d",&a,&b,&c);
	if(a>b && a>c)
	{
		printf("The greatest value is %d",a);
	}
       	else
	{ if(b>a && b>c)
		{
			printf(" The greatest value is %d",b);
		}
		else
		{
			printf(" The greatest value is %d",c);
		}
	} return 0;
}

int fact_val()
{
	int num,f;
again:
	printf("\n Enter the number:");
	scanf("%d",&num);
	if(num <=0)
        goto again;
	f=1;
	while(num >0)
	{
		f = f*num;
		num--;
	}
	printf("\n The value of Factorial of the number is %d",f);
	return 0;
}

int bel_tringle()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
	       	for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		printf("\n");
	} return 0;
}
int upto_nthprime()
{
	int n,i,j;
	printf("Enter the number:");
	scanf("%d",&n);
	printf("\n All prime numbers upto %d is:",n);
	for(i=1;i<=n;i++)
	{ 
		for(j=2;j<i;j++)
		{
			if(i%j ==0)
	                 break;
		}
		if(i==j)
		{
			printf("%d\t",i);
		}
	} return 0;
}
int fib_serise()
{
	int n,f0=0,f1=1,f2;
	printf("Enter the number:");
	scanf("%d",&n);
	printf("\n The Fibonacci Serise :");
	while(f0 < n)
	{
		printf("%d\t",f0);
		f2 = f0+f1;
		f0 = f1;
		f1 = f2;
	} return 0;
}
int sum_serise()
{
	int i,n,f=1;
	float s = 0.0;
	printf("\n Enter the range:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		f=f*i;
		s = s+(i/(float)f);
	}  
	   printf(" The sum of the serise is :%f",s);
	   return 0;
}


