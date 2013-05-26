#include<cstdio>
#include<map>
using namespace std;
int a[10000001], b[10000001];
int main()
{
	int t, p, l, n, m, a1, a2, a3, a4, a5, b1, b2, b3, b4, b5, i, c;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &p, &l);

		scanf("%d %d %d %d %d %d", &n, &a1, &a2, &a3, &a4, &a5);
		scanf("%d %d %d %d %d %d", &m, &b1, &b2, &b3, &b4, &b5);

		map<int, int> ma, mb;
		map<int, int>::iterator mai, mbi;

		ma[a1%p]++; ma[a2%p]++;
		a[1] = a1; a[2] = a2;
		for(i=3; i<=n; i++)
		{
			a[i] = (a[i-2]*a3 + a[i-1]*a4 +a5)%p;
			ma[a[i]]++;
		}

		mb[b1%p]++; mb[b2%p]++;
		b[1] = b1; b[2] = b2;
		for(i=3; i<=m; i++)
		{
			b[i] = (b[i-2]*b3 + b[i-1]*b4 +b5)%p;
			mb[b[i]]++;
		}

		c = 0;
		for(mai = ma.begin(); mai != ma.end(); mai++)
			for(mbi = mb.begin(); mbi != mb.end(); mbi++)
				if((((*mai).first)*((*mbi).first))%p < l)
				{
					c += ((*mai).second)*((*mbi).second);
				}

		printf("%d\n", c);
	}
	
	return 0;
}

