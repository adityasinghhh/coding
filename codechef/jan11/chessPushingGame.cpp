#include<cstdio>
int c, d;
void f(int p[], int k)
{
	if(k == 0)
	{
		if(p[0] == p[1] && p[1] == p[2])
			c++;

		return;
	}

	if(p[0]-p[1] < d)
	{
		if(p[1]-p[2] < d)
		{
			p[0]++;
			f(p, k-1);
		}
		else 
		{
			p[2]++;
			f(p, k-1);
		}
	}
	else 
	{
		if(p[1]-p[2] < d)
		{
			p[1]++;
			f(p, k-1);
		}
		else 
		{
			p[2]++;
			f(p, k-1);
		}
	}
}

int main()
{
	int k, ways, p[3];
	
	scanf("%d %d", &d, &k);

	p[0] = p[1] = p[2] = 0;

	c = 0;
	f(p, k);

	printf("%d\n", c);
}
