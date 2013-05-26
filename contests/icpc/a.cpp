#include<cstdio>
int main()
{
	int n, i, j, k, c=0, temp;
	scanf("%d", &n);
	int a[n+1];
	for(i=0; i<n; i++)
		scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n-1; j++)
		{
			if(a[i]>a[j])
			{
				for(k=i; k<=(i+j-1)/2; k++)
				{
					c++;
					temp = a[k];
					a[k] = a[i+j-k];
					a[i+j-k] = temp;
				}
			}
		}

		for(j=n-2; j<=i+2; j++)
			for(k=i+1; k<=(i+j)/2; k++)
			{
				c++;
				temp = a[k];
				a[k] = a[i+j-k];
				a[i+j-k] = temp;
			}
	}
	printf("%d\n", c);
}

