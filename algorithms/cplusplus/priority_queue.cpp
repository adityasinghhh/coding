#include<queue>
#include<cstdio>
using namespace std;
int main()
{
	priority_queue<int> q;
	int n, i, x;

	scanf("%d", &n);

	for(i=0; i<n; i++)
	{
		scanf("%d", &x);
		q.push(-x);
	}

	for(i=0; i<n; i++)
	{
		printf("%d\n", -q.top());
		q.pop();
	}
}
