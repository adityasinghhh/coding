#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
long long int prime = 13;
long long int rabin_karp(char *a, char *b)
{
	long long int la = strlen(a), lb = strlen(b), val = (long long int)pow((double)prime, (double)lb), ha = 1, hb = 1, i, j;

//	printf("%lld\n", val);

	ha = a[0];
	hb = b[0];
	for(i=1; i<lb; i++)
	{
		ha = ha*prime + a[i];
		hb = hb*prime + b[i];
	//	printf("--%c--,--%lld--:--%c--,--%lld--\n", a[i], ha, b[i], hb);
	}
//	printf("%lld %lld\n", ha, hb);

	for(i=0; i<la-lb+1; i++)
	{
		if(ha == hb)
		{
			for(j=0; j<lb; j++)
				if(a[i+j] != b[j])
					break;

			if(j == lb)
			{
				printf("Match at %lld\n", i);
			}
		}

		ha = ha*prime;
//		printf("%lld:%c %lld %lld\n", i, a[i], ha, hb);
		ha = ha - a[i]*val;
//		printf("%lld:%c %lld %lld\n", i, a[i], ha, hb);
		ha = ha + a[i+lb];
//		printf("%lld:%c %lld %lld\n", i, a[i], ha, hb);
	}
}

int main()
{
	char a[10000], b[10000];
	scanf("%s %s", a, b);
//	printf("%s, %s\n", a, b);

	rabin_karp(a, b);
}
