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
	if(p < 2)
		return 0;

	if(p == 2) 
		return 1;

	if(p%2 == 0)
		return 0;

	int s = p-1;

	while(s%2 == 0)
		s /= 2;

	int i, a, temp, m, b;

	for(i = 0; i<iterations; i++)
	{
		a = rand()%(p-1) + 1;
		temp = s;

		m = mod(a, temp, p);
		
		while(temp != p-1 && m != 1 && m != p-1)
		{
			m = mod();
		}
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
