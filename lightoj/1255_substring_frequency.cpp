#include<cstring>
#include<cstdio>
int T[1234567];
char s[1234567], w[1234567];
void kmp_table()
{
	T[0] = -1;
	T[1] = 0;
	
	int p = 2, cnd = 0, l = strlen(w);

	while(p < l)
	{
		if(w[p-1] == w[cnd])
		{
			cnd++;
			T[p] = cnd;
			++p;;
		}
		else if(cnd > 0)
		{
			cnd = T[cnd];
		}
		else
		{
			T[p] = 0;
			++p;
		}
	}
}

int kmp()
{
	int m = 0, i = 0, ls = strlen(s), lw = strlen(w), cnt = 0;

	while(m+i < ls)
	{
		if(s[m+i] == w[i])
		{
			if(i == lw-1)
			{
				++cnt;
				++m;
				if(T[i] > -1)
					i = T[i];
				else
					i = 0;

			}
			else 
			{
				i++;
			}
		}
		else
		{
			m = m + i - T[i];
				
			if(T[i] > -1)
				i = T[i];
			else
				i = 0;
		}
	}

	return cnt;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int zz=1; zz<=T; ++zz)
	{
		scanf("%s", s);
		scanf("%s", w);
		kmp_table();
		printf("Case %d: %d\n", zz, kmp());
	}

	return 0;
}
