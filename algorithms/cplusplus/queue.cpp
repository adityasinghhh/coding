#include<cstdio>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;

	if(q.size())
		printf("%d\n", q.front());

	if(q.size())
		printf("%d\n", q.back());

	q.push(12);
	
	printf("Front: %d\n", q.front());
	printf("Back: %d\n", q.back());

	q.push(21);
	
	printf("Front: %d\n", q.front());
	printf("Back: %d\n", q.back());

	q.push(32);
	
	printf("Front: %d\n", q.front());
	printf("Back: %d\n", q.back());

	q.pop();
	
	printf("Front: %d\n", q.front());
	printf("Back: %d\n", q.back());
}
