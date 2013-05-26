#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int rmax = 10000;
int main () {
	int T;
	scanf ("%d",&T);

	while (T--) {
		int n, f, x;
		scanf("%d %d", &n, &f);

		vector<int> r;
		for(int i=0; i<n; i++) {
			scanf("%d", &x);
			r.push_back(x);
		}

		double lo = 0, hi = M_PI*rmax*rmax;
		for(int go=0; go<100; go++) {
			double x = (lo+hi)/2;
			int cnt = 0;
			for(int i=0; i<n; i++)
				cnt += (int)floor(M_PI*r[i]*r[i]/x);

			if(cnt < f+1)
				hi=x;
			else
				lo=x;
		}

		printf ("%.4lf\n",lo);
	}

	return 0;
}

