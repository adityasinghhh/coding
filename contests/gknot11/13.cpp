#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	long long int i, j, c, total = 0, count;
//	for(i=1; i<=20; i++)
//	{
i = 2;
long long int p[11] = {0};
long long int a[i+1];

		for(j=0; j<i; j++)
			a[j] = j+1;
		sort(a, a+i);

		count = 0;
		do 
		{
			c = 0;
			for(j=0; j<i-1; j++)
			{
				if(a[j] < a[j+1])
				{
					c++;

					if(c>20)
						break;
				}
			}

			p[c]++;

			if(c>=10 && c<=20)
			{
				count++;
				total++;
			}
		}
		while(next_permutation(a, a+i));

		printf("%lld %lld\n", count, total);
//	}

	printf("%lld\n", total);

	for(i=0; i<11; i++)
		printf("%lld: %lld\n", i, p[i]);
}
