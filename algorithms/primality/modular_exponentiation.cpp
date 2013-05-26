#include<cstdio>
#include<vector>
using namespace std;
int normal_modulo(int a, int b, int c)
{
	long long int res = 1;

	for(int i=0; i<b; i++)
	{
		res *= a;
		res %= c;
	}

	return res%c;
}

int modular_exponentiation(int a, int b, int c)
{
	long long int x = 1, y = a;

	while(b > 0)
	{
		if(b%2 == 1)
		{
			x = (x*y)%c;
		}

		y = (y*y)%c;
		b /= 2;
	}

	return x%c;
}

int mod(int a, int b, int c)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(a);

	int i = 1, k = 1;

	while(k <= b)
	{
		v.push_back((v[i]*v[i])%c);
		i++;
		k *= 2;
	}

	k /= 2;
	i--;

	//printf("k:%d, i:%d\n", k, i);

	long long int x = 1;

	while(b != 0)
	{
	//	printf("%lld\n", x);
		if(b >= k)
		{
			x = (x*v[i])%c;
			b -= k;
		}

		i--;
		k /= 2;
	}

	//printf("%lld\n", x);

	return x%c;
}

int main()
{
	int a, b, c;
	
	while(scanf("%d %d %d", &a, &b, &c) != EOF)
	{
		printf("%d\n", normal_modulo(a, b, c));

		printf("%d\n", modular_exponentiation(a, b, c));
		
		printf("%d\n", mod(a, b, c));
	}

	return 0;
}
