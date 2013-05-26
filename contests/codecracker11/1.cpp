#include<cstdio>
#include<cstring>
int main()
{
	int no, n, i, j, temp;
	char t[1000];

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d", &n);

		char a[n+1][1000];
		int val[n+1], len[n+1];

		for(i=0; i<n; i++)
		{
			scanf("%s", a[i]);
			len[i] = strlen(a[i]);
			val[i] = 0;
			for(j=0; a[i][j]; j++)
				if(a[i][j]<='9' && a[i][j]>='0')
					val[i] = val[i]+a[i][j]-'0';
		}

		for(i=0; i<n; i++)
			for(j=i+1; j<n; j++)
				if(len[i] > len[j] || (len[i] == len[j] && (val[i]> val[j] || (val[i]==val[j] && strcmp(a[i], a[j]) > 0))))
				{
					strcpy(t, a[i]);
					strcpy(a[i], a[j]);
					strcpy(a[j], t);

					temp = val[i];
					val[i] = val[j];
					val[j] = temp;

					temp = len[i];
					len[i] = len[j];
					len[j] = temp;
				}

		for(i=0; i<n; i++)
			printf("%s ", a[i]);
		printf("\n");
	}

	return 0;
}
