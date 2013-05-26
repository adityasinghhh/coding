#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

map<string, int> m;
int n, s1_size[50];
string s1[50];

int f_tracy(string);

int f_teddy(string s)
{
	int i = m[s];
	
	if(i != 0)
		return i;

	int j, len = s.length(), c;

	size_t found;
	for(j=0; j<n; j++)
	{
		if(len < s1_size[j])
			continue;
		
		found = s.find(s1[j]);
		
		if(found != string::npos)
		{
			if((int)found == 0 && len == s1_size[j])
			{
				m[s] = 1;
				return 1;
			}

			if((int)found == 0 && len != s1_size[j])
			{
				if(f_tracy(s.substr((int)found+s1_size[j], len)) == 1)
				{
					m[s] = 1;
					return 1;
				}
			}

			if((int)found+s1_size[j] == len)
			{
				if(f_tracy(s.substr(0, (int)found)) == 1)
				{
					m[s] = 1;
					return 1;
				}
			}

			if((int)found != 0 && (int)found != len-s1_size[j])
			{
				if(f_tracy(s.substr(0, (int)found)) * f_tracy(s.substr((int)found+s1_size[j], len)) == 1)
				{
					m[s] = 1;
					return 1;
				}
			}
		}
	}

	m[s] = -1;
	return -1;
}

int f_tracy(string s)
{
	int i = m[s];
	
	if(i != 0)
		return -i;

	int j, len = s.length(), c;

	size_t found;
	for(j=0; j<n; j++)
	{
		if(len < s1_size[j])
			continue;
		
		found = s.find(s1[j]);
		
		if(found != string::npos)
		{
			if((int)found == 0 && len == s1_size[j])
			{
				m[s] = 1;
				return -1;
			}

			if((int)found == 0 && len != s1_size[j])
			{
				if(f_teddy(s.substr((int)found+s1_size[j], len)) == -1)
				{
					m[s] = 1;
					return -1;
				}
			}

			if((int)found+s1_size[j] == len)
			{
				if(f_teddy(s.substr(0, (int)found)) == -1)
				{
					m[s] = 1;
					return -1;
				}
			}

			if((int)found != 0 && (int)found != len-s1_size[j])
			{
				if(f_teddy(s.substr(0, (int)found)) * f_teddy(s.substr((int)found+s1_size[j], len)) == -1)
				{
					m[s] = 1;
					return -1;
				}
			}
		}
	}

	m[s] = -1;
	return 1;
}

int main()
{
	int no, i, j, l;
	string s;
	char a[100];
	size_t found;

	scanf("%d", &no);
	while(no--)
	{
		m.clear();
		scanf("%s", a);
		s = a;
		l = strlen(a);

		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", a);
			s1[i] = a;

			found = s.find(s1[i]);
			if(found == string::npos)
			{
				i--;
				n--;
			}
		}

		if(n == 0)
		{
			printf("Tracy\n");
			continue;
		}

		sort(s1, s1+n);

		for(i=0; i<n; i++)
			s1_size[i] = s1[i].length();

		if(f_teddy(s) == -1)
			printf("Tracy\n");
		else
			printf("Teddy\n");
	}

	return 0;
}
