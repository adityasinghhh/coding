#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
map<long long int, bool> p;

int main()
{
	long long int z=0, i, no, n, c, v;

	for(i=0; i<=1<<16; i++)
		p[i*i] = 1;

	scanf("%lld", &no);
	while(no--)
	{
		scanf("%lld", &n);

		c = 0;
		for(i=0; i*i<=n; i++)
		{
//			printf("%lld %lld %lld\n", i, i*i, n);
			if(p[n-i*i] == 1)
			{
//				printf("%lld %lld\n", i*i, n-i*i);
				c++;
			}
		}
		if(c == 1)
			printf("%lld\n", c);
		else
			printf("%lld\n", c/2);
	}
	return 0;
}
