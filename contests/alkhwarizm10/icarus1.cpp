#include<cstdio>
#include<iostream>
#include<map>
#include<utility>
using namespace std;
int main()
{
	int no, n, s, i, j, count, degree, c, d, x, y;
	char ch;

	pair<int, int> p1;

	int q[100000][2];

	scanf("%d", &no);

	for(int zz = 1; zz<=no; zz++)
	{
		map <pair<int, int>,int> m;
		map <pair<int, int>,int>::iterator it;

		scanf("%d %d", &n, &s);
		getchar();

		for(i=0; i<s; i++)
		{
			scanf("%c %d %d", &ch, &x, &y);
			getchar();

			p1 = make_pair(x, y);

			m[p1] = ch;
		}
		
		int B[s+1][2], W[s+1][2], zb = 0, zw = 0, ii, jj;

		for(it = m.begin(); it != m.end(); it++)
		{
			p1 = (*it).first;
			x = p1.first;
			y = p1.second;
			
			ch = (*it).second;

			if(ch == 0 || ch == 1)
				continue;

			//printf("%d %d %c\n", x, y, ch);

			map <pair<int, int>,int> m1;

			m[p1] = 1;
			q[0][0] = x;
			q[0][1] = y;

			c = 0; 
			d = 1;

			count = 0;
			degree = 0;

			while(c < d)
			{
				ii = q[c][0];
				jj = q[c][1];

				//printf("%d,%d:%d ", ii, jj, degree);

		//		printf("%d %d %c\n", ii, jj, m[make_pair(ii, jj)]);

				if(ii > 1)
				{
					p1 = make_pair(ii-1, jj);
					if(m[p1] == 0 && m1[p1] == 0)
					{
						//printf("%d %d\n", ii-1, jj);
						m1[p1] = 1;
						degree++;
					}
					else if(m[p1] == ch)
					{
						m[p1] = 1;
						q[d][0] = ii-1;
						q[d++][1] = jj;
					}
				}
				
				if(jj > 1)
				{
					p1 = make_pair(ii, jj-1);
					if(m[p1] == 0 && m1[p1] == 0)
					{
						//printf("%d %d\n", ii, jj-1);
						m1[p1] = 1;
						degree++;
					}
					else if(m[p1] == ch)
					{
						m[p1] = 1;
						q[d][0] = ii;
						q[d++][1] = jj-1;
					}
				}

				if(ii < n)
				{
					p1 = make_pair(ii+1, jj);
					if(m[p1] == 0 && m1[p1] == 0)
					{
						///printf("%d %d\n", ii+1, jj);
						m1[p1] = 1;
						degree++;
					}
					else if(m[p1] == ch)
					{
						m[p1] = 1;
						q[d][0] = ii+1;
						q[d++][1] = jj;
					}
				}

				if(jj < n)
				{
					p1 = make_pair(ii, jj+1);
					if(m[p1] == 0 && m1[p1] == 0)
					{
						//printf("%d %d\n", ii, jj+1);
						m1[p1] = 1;
						degree++;
					}
					else if(m[p1] == ch)
					{
						m[p1] = 1;
						q[d][0] = ii;
						q[d++][1] = jj+1;
					}
				}

				c++;
			}
//			printf("\n");

			if(ch == 'B')
			{
//				printf("B %d %d %d %d\n", x, y, d, degree);
				B[zb][0] = d;
				B[zb++][1] = degree;
			}
			else if(ch == 'W')
			{
//				printf("W %d %d %d %d\n", x, y, d, degree);
				W[zw][0] = d;
				W[zw++][1] = degree;
			}
		}

		int temp;

		for(i=0; i<zb; i++)
			for(j=i+1; j<zb; j++)
				if(B[i][0] < B[j][0] || (B[i][0] == B[j][0] && B[i][1] < B[j][1]))
				{
					temp = B[i][0];
					B[i][0] = B[j][0];
					B[j][0] = temp;
					temp = B[i][1];
					B[i][1] = B[j][1];
					B[j][1] = temp;
				}

		for(i=0; i<zw; i++)
			for(j=i+1; j<zw; j++)
				if(W[i][0] < W[j][0] || (W[i][0] == W[j][0] && W[i][1] < W[j][1]))
				{
					temp = W[i][0];
					W[i][0] = W[j][0];
					W[j][0] = temp;
					temp = W[i][1];
					W[i][1] = W[j][1];
					W[j][1] = temp;
				}

		printf("Case #%d:\n", zz);
		for(i=0; i<zb; i++)
			printf("B %d %d\n", B[i][0], B[i][1]);
		for(i=0; i<zw; i++)
			printf("W %d %d\n", W[i][0], W[i][1]);
		printf("\n");
	}

	return 0;
}
