#include<cstdio>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;

	if(s.size())
		printf("%d\n", s.top());

	s.push(12);
	
	printf("Top: %d\n", s.top());

	s.push(21);
	
	printf("Top: %d\n", s.top());

	s.push(32);
	
	printf("Top: %d\n", s.top());

	s.pop();
	
	printf("Top: %d\n", s.top());
}
