#include<cstdio>
#include<map>
#include<set>
using namespace std;
int a[10000001], b[10000001], marka[10000001], markb[10000001];
int main()
{
	int t, p, l, n, m, a1, a2, a3, a4, a5, b1, b2, b3, b4, b5, i, c;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &p, &l);

		scanf("%d %d %d %d %d %d", &n, &a1, &a2, &a3, &a4, &a5);
		scanf("%d %d %d %d %d %d", &m, &b1, &b2, &b3, &b4, &b5);

		for(i=0; i<p; i++)
			marka[i] = markb[i] = 0;

		set<int> ma, mb;
		set<int>::iterator mai, mbi;

		ma.insert(a1%p);
		ma.insert(a2%p);
		a[1] = a1; a[2] = a2;
		marka[a1%p]++; marka[a2%p]++;
		for(i=3; i<=n; i++)
		{
			a[i] = (a[i-2]*a3 + a[i-1]*a4 +a5)%p;
			ma.insert(a[i]);
			marka[a[i]]++;
		}

		mb.insert(b1%p);
		mb.insert(b2%p);
		markb[b1%p]++; markb[b2%p]++;
		b[1] = b1; b[2] = b2;
		for(i=3; i<=m; i++)
		{
			b[i] = (b[i-2]*b3 + b[i-1]*b4 +b5)%p;
			mb.insert(b[i]);
			markb[b[i]]++;
		}

		c = 0;
		for(mai = ma.begin(); mai != ma.end(); mai++)
			for(mbi = mb.begin(); mbi != mb.end(); mbi++)
				if(((*mai)*(*mbi))%p < l)
				{
					c += marka[*mai]*markb[*mbi];
				}

		printf("%d\n", c);
	}
	
	return 0;
}

