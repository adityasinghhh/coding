/* You have 100 doors in a row that are all initially closed. You make 100 passes by the doors. The first time through, you visit every door and toggle the door (if the door is closed, you open it; if it is open, you close it). The second time you only visit every 2nd door (door #2, #4, #6, ...). The third time, every 3rd door (door #3, #6, #9, ...), etc, until you only visit the 100th door. 
 *
 * Solution: It is clear that the doors that would remain open are the ones that are numbered by numbers that have odd number of divisors. Only perfect squares have odd number of divisors, hence only perfect squares remain open. */

#include<cstdio>
int main()
{
	int n, i;

	while(scanf("%d", &n) != EOF)
	{
		for(i=1; i*i<=n; i++)
			printf("%d ", i*i);
		printf("\n");
	}

	return 0;
}
