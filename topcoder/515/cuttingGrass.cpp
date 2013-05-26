#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
class CuttingGrass
{
	public:
		vector<int> _init, _grow;
		int _H;

		int theMin(vector<int> init, vector<int> grow, int H)
		{
			_init = init;
			_grow = grow;
			_H = H;

			int size = init.size(), i, s=0, c, j;
			for(i=0; i<size; i++)
				s+=init[i];

			if(s <= H)
				return 0;

			vector<pair<int,int> > x;
			for(i=0; i<size; i++)
				x.push_back(make_pair(grow[i], i));
			sort(x.begin(), x.end());
			s = 0;
			for(i=0; i<size; i++)
				s+=(size-i-1)*x[i].first;

			if(s > H)
				return -1;

			c=0;
			j=0;
			int maxi;
			while(true)
			{
				maxi = 0;
				for(i=0; i<size; i++)
					if(init[maxi] + grow[maxi] < init[i] + grow[i])
						maxi = i;

				for(i=0; i<size; i++)
					init[i] += grow[i];

				init[maxi] = 0;

				printf("%d: ", c);
				s=0;
				for(i=0; i<size; i++)
				{
					printf("%d ", init[i]);
					s += init[i];
				}

				printf("Sum: %d\n", s);

				if(s <= H)
					return c;
				c++;					
			}		

			return c;				
		}
};

int main()
{
	vector<int> init, grow;
	int H, N, x, i;

	scanf("%d", &N);
	for(i=0; i<N; i++)
	{
		scanf("%d", &x);
		init.push_back(x);
	}
	for(i=0; i<N; i++)
	{
		scanf("%d", &x);
		grow.push_back(x);
	}
	scanf("%d", &H);

	CuttingGrass cg;

	printf("%d\n", cg.theMin(init, grow, H));

	return 0;
}
