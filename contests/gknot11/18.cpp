#include<cstdio>
int f1 = 1, f2 = 1, f3 = 3, f4 = 4, t, i;

int main()
{
	printf("%d\n%d\n%d\n%d\n", f1, f2, f3, f4);

	for(i=5; i<100; i++)
	{
		t = f4;
		f4 = 13*f4 + 5*f3 + 7*f2 + 17*f1;
		f1 = f2;
		f2 = f3;
		f3 = t;

		printf("%d\n", f4);
	}
}
