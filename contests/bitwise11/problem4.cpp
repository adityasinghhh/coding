#include<cstdio>
#include<map>
#include<utility>
using namespace std;
int main()
{
	int t, x, y, i;
	char a[1000111];
	pair<int, int> p;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%s", a);

		map<pair<int, int>, bool> m;

		x = y = 0;

		p = make_pair(x, y);
		m[p] = 1;

		for(i=0; a[i]; i++)
		{
			if(a[i] == '0')
				p.first++;
			else if(a[i] == '1')
				p.second++;
			else if(a[i] == '2')
				p.first--;
			else
				p.second--;

			if(m[p])
				break;

			m[p] = 1;
		}

		if(a[i+1] == 0 && p.first == 0 && p.second == 0)
			printf("YES");
		else
			printf("NO");
		printf("\n");
	}
}
