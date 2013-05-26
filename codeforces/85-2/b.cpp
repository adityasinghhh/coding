#include<cstdio>
bool check(int x, int n) {
	return (x == n || x == n+1);
}

int main()
{
	int n, x, y;

	scanf("%d %d %d", &n, &x, &y);

	n = n/2;

	if(n == 1) {
		printf("NO\n");
	} else if(n == 2) {
		if(x == n || x == n+1 || y == n || y == n+1)
			printf("NO\n");
		else
			printf("YES\n");
	} else {
		if(check(x, n) && check(y, n))
			printf("NO\n");
		else 
			printf("YES\n");
	}

	return 0;	
}
