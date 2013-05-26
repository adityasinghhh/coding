#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
bool check(pair<int, int> p1, pair<int, int> p2) {
	return (p1.first > p2.first && p1.second > p2.second);
}

int main() {
	int zz = 1, n, i, x, y, j;
	while(scanf("%d", &n)) {
		if(n == 0)
			return 0;

		if(zz != 1)
			printf("\n");
	
		vector<pair<int, int> > v1, v2;
		for(i=0; i<n; i++) {
			scanf("%d %d", &x, &y);
			v1.push_back(make_pair(x, y));
			v2.push_back(make_pair(x, y));
		}

		sort(v1.begin(), v1.end());

		printf("Case %d:\n", zz++);
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++)
				if(check(v1[j], v2[i]))
					break;

			if(j == n)
				printf("-1 -1\n");
			else
				printf("%d %d\n", v1[j].first, v1[j].second);
		}
	}
}
