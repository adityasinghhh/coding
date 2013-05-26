#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	char a[1000];
	int T, n, i;
	scanf("%d", &T);
	while(T--) {
		vector<int> v;
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			scanf("%s", a);

			if(strcmp(a, "lxh")) {
				v.push_back(0);
			} else {
				v.push_back(1);
			}
		}

		for(i=0; i<n-1; i++)
			v[i+1] = v[i]^v[i+1];


		printf("%s\n", v[n-1] ? "lxh" : "hhb");
	}

	return 0;
}
