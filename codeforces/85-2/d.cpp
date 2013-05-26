#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	int T, v, x, y, z=0, i, count, f1, f2, j, flag1, flag2;
	scanf("%d", &T);

	vector<int> X, Y;

	while(T--) {
		scanf("%d %d", &x, &y);
		X.push_back(x);
		Y.push_back(y);

		v = (int)sqrt((double)x);
		count = 0;
		for(i=1; i<=v; i++) 
			if(!(x%i)) {
				f1 = i;
				f2 = x/i;

				flag1 = flag2 = 0;
				for(j=1; j<=y; j++) {
					if(!(X[z-j]%f1)) {
						flag1 = 1;
					} 

					if(f1 == f2) {
						if(flag1)
							break;

						continue;
					}

					if(!(X[z-j]%f2)) {
						flag2 = 1;
					}

					if(flag1&flag2)
						break;
				}
				
				if(!flag1)
					count++;
				if(f1-f2 && !flag2)
					count++;
			}

		printf("%d\n", count);
		z++;
	}

	return 0;
}
