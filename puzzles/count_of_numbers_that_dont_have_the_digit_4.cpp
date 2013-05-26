#include<cstdio>
#include<cmath>
int f1(int);

int f(int n)
{
	if(n < 10)
	{
		if(n >= 4)
			return 1;
		return 0;
	}

	int count = 0, x = n, first;

	while(x != 0)
	{
		count++;
		first = x%10;
		x /= 10;
	}

	if(first < 4)
		return first*f1(count-1) + f(n%(int)pow(10.0, (int)count-1));
	else if(first == 4)
		return (n%(int)pow(10.0, (int)count-1)+1) + first*f1(count-1);
	else
		return pow(10.0, (int)count-1) + (first-1)*f1(count-1) + f(n%(int)pow(10.0, (int)count-1));
}

int f1(int count)
{
	if(count == 2)
		return 19;
	if(count == 1)
		return 1;

	return (int)pow(10.0, (double)count-1) + 9*f1(count-1);
}

int main()
{
	int n;

	while(scanf("%d", &n) != EOF)
	{
		printf("%d\n", f(n));
	}
}
