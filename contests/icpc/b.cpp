#include<cstdio>
int gcd(int a, int b)
{
	if(a%b == 0)
		return b;
	return gcd(b, a%b);
}

int main()
{
	char a[101];
	int h, t, i, no,g;
	scanf("%d", &no);
	while(no--)
	{
		scanf("%s", a);

		h=t=0;
		for(i=0; a[i]!=0; i++)
			if(a[i] == 'H')
				h++;
			else
				t++;
		g = gcd(h+t+2, h+1);
		printf("%d %d\n", (h+1)/g, (h+t+2)/g);
	}
	return 0;
}
