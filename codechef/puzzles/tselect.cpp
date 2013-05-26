#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int no, n, z, i, sum;

	scanf("%d", &no);

	for(z=0; z<no; z++)
	{
		scanf("%d", &n);

		int a[n+1];

		sum = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		sum /= 2;

		while(n != 1)
		{
			sort(a, a+n);

			a[n-2] = a[n-1] - a[n-2];
			n--;
		}

		printf("%d %d\n", sum-a[0], sum+a[0]);
	}

	return 0;
}
