#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	long long int no, n, i, j, min, max, a[50001], s, x;
	vector<long long int> v;
	scanf("%lld", &no);
	while(no--)
	{
		v.clear();
		scanf("%lld", &n);
//		printf("%lld\n", n);

		for(i=0; i<n; i++)
		{	
//			scanf("%lld", &a[i]);
			scanf("%lld", &x);
			v.push_back(x);
		}
/*printf("here\n");

		for(j=0; j<n; j++)
			printf("%lld ", v[j]);
		printf("\n");
*/
		s=0;
		for(i=0; ; i++)
		{
			min = 0;
			for(j=0; j<n; j++)
				if(v[min] > v[j])
					min = j;

//			printf("%lld:%lld\n", min, v[min]);

			max = min;
			for(j=min; j<n; j++)
				if(v[max] < v[j])
					max = j;
			
//			printf("%lld:%lld\n", max, v[max]);

			if(max == min)
				break;

			s+=v[max]-v[min];
			v.erase(v.begin()+max);
			v.erase(v.begin()+min);

			n-=2;
/*		for(j=0; j<n; j++)
			printf("%lld ", v[j]);
		printf("\n");
	*/	}
		printf("%lld\n", s);
	}
	return 0;
}
