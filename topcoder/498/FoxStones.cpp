#include<cstdio>
#include<vector>
#include<map>
using namespace std;
class FoxStones
{
	public:
		int maximum(int a, int b)
		{
			return a>b?a:b;
		}

		int abs(int a)
		{
			return a>0?a:-a;
		}

		int getCount(int N, int M, vector<int> sx, vector<int> sy)
		{
			int size = sx.size();
			int i, j, k, a[201][201] = {0};

			int fact[11];
			fact[0] = 1;
			for(i=1;i<11;i++)
				fact[i] = fact[i-1]*i;


			for(i=0; i<size; i++)
				a[sx[i]][sy[i]] = 1;

			map<vector<int>, int> m;
			map<vector<int>, int>::iterator it;

			for(i=1; i<=N; i++)
				for(j=1; j<=M; j++)
				{
					if(a[i][j] == 1)
						continue;

					vector<int> dist;
					for(k=0; k<size; k++)
					{
						printf("Pushing %d at %d,%d\n", maximum(abs(i-sx[k]), abs(j-sy[k])), i, j);
						dist.push_back(maximum(abs(i-sx[k]), abs(j-sy[k])));
					}

					m[dist]++;						
				}			

			int c = 1;
			for(it=m.begin(); it!=m.end(); it++)
			{
				int s=(*it).first.size();
				for(i=0; i<s; i++)
					printf("%d ", (*it).first[i]);
				printf("\n");
				c = (c*fact[(*it).second])%1000000009;
			}
			return c;
		}
};
