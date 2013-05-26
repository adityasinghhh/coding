#include<cstdio>
int main()
{
	long long int a[5] = {3, 5, 17, 257, 65537};
	long long int i, j, k, l, m, sum;

	sum = 0;
	for(i=0; i<5; i++)
	{
		sum += a[i];

		for(j=0; j<5; j++)
		{
			if(j == i)
				continue;

			sum += a[i]*a[j];

			for(k=0; k<5; k++)
			{
				if(k == i || k == j)
					continue;

				sum += a[i]*a[j]*a[k];

				for(l=0; l<5; l++)
				{
					if(l==i || l==j || l==k)
						continue;

					sum += a[i]*a[j]*a[k]*a[l];

					for(m=0; m<5; m++)
					{
						if(m==i || m==j || m==k || m==l)
							continue;

						sum += a[i]*a[j]*a[k]*a[l]*a[m];
					}
				}
			}
		}
	}

	printf("%lld\n", sum);
}
