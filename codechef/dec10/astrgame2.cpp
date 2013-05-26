#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
map<vector<string>, int> m;
int n;
string s1[50];
int s1_size[50];

int f_tracy(vector<string>, int);

int f_teddy(vector<string> v, int z)
{
	int val = m[v];
	
	if(val != 0)
		return val;

	int l = v.size(), i, j, len;
	vector<string> v1;

	size_t found;
	for(j=z; j<n; j++)
	{
		for(i=0; i<l; i++)
		{
			len = v[i].size();

			if(len < s1_size[j])
				continue;

			found = v[i].find(s1[j]);

			if(found != string::npos)
			{
				v1 = v;
				v1.erase(v1.begin()+i);

				if((int)found != 0)
					v1.push_back(v[i].substr(0, (int)found));

				if((int)found != len-s1_size[j])
					v1.push_back(v[i].substr((int)found+s1_size[j], len));

				sort(v1.begin(), v1.end());
				if(v1.empty() || f_tracy(v1, z) == 1)
				{
					m[v] = 1;
					return 1;
				}
			}
		}
	}

	m[v] = -1;
	return -1;
}

int f_tracy(vector<string> v, int z)
{
	int val = m[v];

	if(val != 0)
		return -val;

	int l = v.size(), i, j, len;
	vector<string> v1;

	size_t found;
	for(j=z; j<n; j++)
	{
		for(i=0; i<l; i++)
		{
			len = v[i].size();
			
			if(len < s1_size[j])
				continue;

			found = v[i].find(s1[j]);

			if(found != string::npos)
			{
				v1 = v;
				v1.erase(v1.begin()+i);
			
				if((int)found != 0)
					v1.push_back(v[i].substr(0, (int)found));

				if((int)found != len-s1_size[j])
					v1.push_back(v[i].substr((int)found+s1_size[j], len));

				sort(v1.begin(), v1.end());
				if(v1.empty() || f_teddy(v1, z) == -1)
				{
					m[v] = 1;
					return -1;
				}
			}
		}
	}

	m[v] = -1;
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
			s1_size[i] = s1[i].length();

			found = s.find(s1[i]);
			if(found == string::npos)
			{
				i--;
				n--;
			}
		}

		vector<string> v;
		v.push_back(s);

		if(f_teddy(v, 0) == -1)
			printf("Tracy\n");
		else
			printf("Teddy\n");
	}

	return 0;
}
