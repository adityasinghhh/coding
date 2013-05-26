#include<cstdio>
int main()
{
	int i, j;
	for(i=11; ; i+=11)
	{
		for(j=2; j<11; j++)
			if(i%j!=1)
				break;

		if(j==11)
			break;
	}
	printf("%d\n", i);
}
