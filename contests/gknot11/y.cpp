#include<cstdio>
int main()
{
	char ch;
	int i, s=0;
	for(i=0; i<100; i++)
	{
		ch = getchar();
		s+=ch-'0';
	}
	printf("%d\n",s);
}
