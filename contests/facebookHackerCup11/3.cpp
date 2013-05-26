#include<cstdio>
int main()
{
	int no, c, i;
	char a[10000];

	scanf("%d", &no);

	while(no--)
	{
		int p[257] = {0};

		scanf(" %[^\n]", a);

		for(i=0; a[i]!=0; i++)
			p[a[i]]++;

		c=0;
		for(i=0; i<257; i++)
			if(p[i])
			{
				printf("%c::", i);
				c++;
			}
		printf("\n");
		printf("%d\n", c);
	}

	return 0;
}

