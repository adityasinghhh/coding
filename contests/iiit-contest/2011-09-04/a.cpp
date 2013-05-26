#include<cstdio>
#include<vector>
int main() {
	while(scanf("%d %d", &n, &m)) {
		if(n == 0 && m == 0)
			return 0;

		vector<vector<int> > v1;
		for(i=0; i<m; i++) {
			vector<int> v;
			scanf("%d", &k);
			while(k--) {
				scanf("%d", &x);
				v.push_back(x);
			}

			v1.push_back(v);
		}

		for(i=0; i<m; i++)
	}
}
