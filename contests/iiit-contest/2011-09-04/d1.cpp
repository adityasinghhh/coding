#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int T, n, f, i, j;
	double x;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &f);
		f++;

		vector<double> v;
		vector<int> v1;
		for(i=0; i<n; i++) {
			scanf("%lf", &x);
			v.push_back(x*x);
			v1.push_back(0);
		}

		sort(v.begin(), v.end());

		i = n-1;
		while(f) {
			v1[i]++;
			i--;

			f--;

			if(i == -1)
				i = n-1;
		}

		for(i=0; i<n; i++) {
			for(j=i+1; j<n; j++)
				if(v[i]/v1[i] < v[j]/(v1[j]+1))
				{
					v1[i]--;
					if(!v[i])
						break;

					v1[j]++;
					j--;
				}
		}

		double mini = (double)INT_MAX;
		for(i=0; i<n; i++)
			if(v1[i])
				if(mini > v[i]/v1[i])
					mini = v[i]/v1[i];

		printf("%.4lf\n", M_PI*mini);
	}

	return 0;
}
