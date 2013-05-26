#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
string s1[50];

string remove_s1(string s1, string s2)
{
	size_t found = s1.find(s2);

	if(found != string::npos)
		s1.erase(found, s2.length());

	return s1;
}

int f(string s, int count)
{
	string s2;
	int i;

	for(i=0; i<n; i++)
	{
		s2 = remove_s1(s, s1[i]);

		if(s2 == s || s2.empty())
			continue;
		else 
			return f(s2, count+1);
	}

	return count;
}

int main()
{
	int t, i, flag;
	string s;
	char a[1000];
	size_t found;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%s", a);
		s = (string)a;

		scanf("%d", &n);

		for(i=0; i<n; i++)
		{
			scanf("%s", a);
			s1[i] = (string)a;

			found = s.find(s1[i]);

			if(found == string::npos)
			{
				i--;
				n--;
			}			
		}

		sort(s1, s1+n);

		flag = f(s, 0);

		if(flag == 0 || flag%2 == 1)
			printf("Tracy\n");
		else
			printf("Teddy\n");
	}

	return 0;
}
