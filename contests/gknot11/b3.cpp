#include<cstdio>
#include<cstring>
int p[26][26][26][26][26] = {0}, i, j, k, p1[125] = {0}, p2[125][125] = {0}, l, m;
int main()
{
	char a[1000];
	printf("here\n");

	while(scanf("%s", a) != EOF)
	{
		int l = strlen(a);
		for(i=0;i<l-4;i++)
			p[a[i]-'a'][a[i+1]-'a'][a[i+2]-'a'][a[i+3]-'a'][a[i+4]-'a']++;

		for(i=0; i<l; i++)
			p1[a[i]]++;

		for(i=0; i<l-1; i++)
			p2[a[i]][a[i+1]]++;
	}

	for(i=97; i<=122; i++)
		for(j=97; j<=122; j++)
			for(k=97; k<=122; k++)
				for(l=97; l<=122; l++)
					for(m=97; m<=122; m++)
						if(p[i-'a'][j-'a'][k-'a'][l-'a'][m-'a'])
							printf("%c%c%c%c%c: %d\n", i, j, k, l, m, p[i-'a'][j-'a'][k-'a'][l-'a'][m-'a']);


	for(i=97; i<=122; i++)
		printf("%c: %d\n", i, p1[i]);
	
	for(i=97; i<=122; i++)
		for(j=97; j<=122; j++)
			if(p2[i][j])
			printf("%c%c: %d\n", i,j,p2[i][j]);

}
