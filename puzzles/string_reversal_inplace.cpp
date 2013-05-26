#include<cstdio>
#include<cstring>
int main()
{
	char a[10000];
	int b;

	scanf("%s", a);

	int i, l = strlen(a)-1;

	for(i=0; i<l; i++, l--)
	{
		a[i] = a[i]^a[l];
		a[l] = a[i]^a[l];
		a[i] = a[i]^a[l];
	}

	printf("%s\n", a);
}
