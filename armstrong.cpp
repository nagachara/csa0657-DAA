#include<stido.h>
int main()
{
	int num1=n;
	arm=0;
	while(n!=0)
	{
		int rem=n%10;
		arm=arm+(rem*rem*rem);
		n=n/10;
	}
	if(n==arm)
	printf(" it is armstrong number");
	else
	printf(" it is not armstrong");
	}
}