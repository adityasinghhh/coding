#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
	int T, n, j, size, m, i, x;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);

		vector<int> v, v1;
		for(i=0; i<n; i++) {
			scanf("%d", &x);
			v1.push_back(x);
		}

		size = v1.size();
		for(i=size-1; i>=0; i--)
			v.push_back(v1[i]);

		i=0;
		while(true) {
			for(j=i; j<size; j++) 
				if(v[j] > v[i])
					break;

			if(j == size) {
				v[i] = -v[i];
				if(i == m)
				{
					printf("%d\n", i);
					break;
				}
			} else {
				v.push_back(v[i]);
				v[i] = -999;
				if(i == m)
					m = size;
				size++;
			}
			i++;
		}
	}

	return 0;
}
