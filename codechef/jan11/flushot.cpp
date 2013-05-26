#include<cstdio>
double abs(double a)
{
	if(a < 0.000001)
		return -a;
	return a;
}

int main()
{
	int no, n, i, j;
	double t, v, diff;

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d %lf", &n, &t);

		printf(":: ::\n");

		double a[n+1], b[n+1];

		for(i=0; i<n; i++)
		{
			scanf("%lf", &a[i]);
			b[i] = a[i];
		}

		for(i=0; i<n-1; i++)
		{
			if(b[i]-b[i+1] > 0.00000)
			{
				printf("here\n");
				b[i+1] = b[i]+t;
			printf("b: ");
			for(int ii=0; ii<n; ii++)
				printf("%lf ", b[ii]);
			printf("\n");
				continue;
			}

			v = abs(b[i]-b[i+1]);
			diff = t-v;

			if(diff > 0.000001)
			{
				diff /= 2.0;
				if(b[0]-diff > 0.000001)
				{
					for(j=i; j>=0; j--)
					{
						b[j] -= diff;

						if(j != 0 && b[j]-b[j-1]-t > 0.00001)
							break;
					}

					b[i+1] += diff;
				}
				else
				{
					b[i+1] += 2.0*diff;
				}
			}

			printf("b: ");
			for(int ii=0; ii<n; ii++)
				printf("%lf ", b[ii]);
			printf("\n");
		}

		for(i=0; i<n; i++)
			printf("%lf ", a[i]);
		printf("\n");

		for(i=0; i<n; i++)
			printf("%lf ", b[i]);
		printf("\n");
	}

	return 0;
}
