#include<stdio.h>
int main()
{
	int i, no, n, m;

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d", &n);

		m = n;

		for(i=2; i*i<=n; i++)
		{
			if(n%i == 0)
			{
				m=m/i*(i-1);

				while(n%i == 0)
					n/=i;
			}
		}

		if(n>1)
			m=m/n*(n-1);

		printf("%d\n", m);
	}

	return 0;
}





