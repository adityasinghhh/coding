#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
int main() {
	int T, n, i, top, f, pop_count, count;
	double r, v, t, pi = 3.14159265358979323846264338327950;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &f);
		f++;

		priority_queue<double> pq;
		for(i=0; i<n; i++) {
			scanf("%lf", &r);
			pq.push(r);
		}

		pop_count = f%n;
		t = pq.top();
		while(pop_count--) {
			t = pq.top();
			pq.pop();
		}

		count = f/n;
		if(f%n)
			count++;

		printf("%.4lf\n", pi*t*t/count);
	}

	return 0;
}
