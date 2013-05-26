#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int i, j, k, l, m, n, c=0, a[10];	
	for(i=1; i<=20; i++)
		for(j=1; j<=20; j++)
			for(k=1; k<=20; k++)
				for(l=1; l<=20; l++)
					for(m=1; m<=20; m++)
						for(n=1; n<=20; n++)
						{
							a[0] = i;
							a[1] = j;
							a[2] = k;
							a[3] = l;
							a[4] = m;
							a[5] = n;

							int xo=0;
							int p=0;
							for(int ii=0; ii<6; ii++)
							{
								xo^=a[ii];
								if(a[ii]==1)p++;
							}
							if(p==6)
								c += 6%2==0?1:0;
							else if(xo) 
								c++;
						}
	printf("%d\n", c);

	return 0;
}
