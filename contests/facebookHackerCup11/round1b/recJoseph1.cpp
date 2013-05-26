#include<cstdio>
#include<utility>
#include<map>
using namespace std;
map<pair<long long int, long long int>, bool> m;
long long int j(long long int n, long long int k)
{
	//	pair<long long int, long long int> p = make_pair(n, k);

	//	if(m[p])
	//		return m[p];

	if(n == 1)
	{
//		m[p] = 0;
		return 0;
	}


	long long int ret =(j(n-1, k)+k)%n;

//	m[p] = ret;
	return ret;
}

int main()
{
	long long int no, n, k, f, i;

	while(true)
	{
		scanf("%lld %lld", &n, &k);

		if(n == 0 && k == 0)
			return 0;
		
		f = k;
		
		for(i=1; i<n-1; i++)
		{
			f = (f+k)%n;
			printf("%lld ", f);
		}
		printf("\n");
			printf("%lld\n", f);


	}
}
