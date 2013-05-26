#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
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

bool prime(int p, int iterations)
{
	if(p == 1)
		return 0;

	int i, a;

	for(i = 0; i<iterations; i++)
	{
		a = rand()%(p-1) + 1;

		if(mod(a, p-1, p) != 1)
			return 0;
	}

	return 1;
}

int main()
{
	int p;
	
	while(scanf("%d", &p) != EOF)
	{
		if(prime(p, 100) == 1)
			printf("%d is prime\n", p);
		else
			printf("%d is not prime\n", p);
	}

	return 0;
}
