#include<iostream>
#include<queue>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
map<vector<string>, int> m;
map<vector<string>, int> m1;
int n;
string s1[50];
int s1_size[50];

int f_tracy(vector<string>);

int f_teddy(vector<string> v)
{
	int val = m[v];
	
	if(val != 0)
		return val;

	int l = v.size(), i, j, len;
	vector<string> v1;

	size_t found;
	for(i=0; i<l; i++)
	{
		len = v[i].size();
		for(j=0; j<n; j++)
		{
			found = v[i].find(s1[j]);
			if(found != string::npos)
			{
				v1 = v;
				v1.erase(v1.begin()+i);
				if((int)found != 0)
					v1.push_back(v[i].substr(0, (int)found));

				if((int)found != len-s1_size[j])
					v1.push_back(v[i].substr((int)found+s1_size[j], len));

				if(v1.empty() || f_tracy(v1) == 1)
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

int f_tracy(vector<string> v)
{
	int val = m1[v];

	if(val != 0)
		return val;

	int l = v.size(), i, j, len;
	vector<string> v1;

	size_t found;
	for(i=0; i<l; i++)
	{
		len = v[i].size();
		for(j=0; j<n; j++)
		{
			found = v[i].find(s1[j]);
			if(found != string::npos)
			{
				v1 = v;
				v1.erase(v1.begin()+i);
				if((int)found != 0)
					v1.push_back(v[i].substr(0, (int)found));

				if((int)found != len-s1_size[j])
					v1.push_back(v[i].substr((int)found+s1_size[j], len));

				if(v1.empty() || f_teddy(v1) == -1)
				{
					m1[v] = -1;
					return -1;
				}
			}
		}
	}

	m1[v] = 1;
	return 1;
}


int main()
{
	int no, i, j, l;
	string s;
	vector<string> v;
	size_t found;

	scanf("%d", &no);
	while(no--)
	{
		m.clear();
		m1.clear();
		cin>>s;
		l = s.size();

		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			cin>>s1[i];
			s1_size[i] = s1[i].size();

			found = s.find(s1[i]);
			if(found == string::npos)
			{
				i--;
				n--;
			}
		}

		v.clear();
		v.push_back(s);

		if(f_teddy(v) == -1)
			printf("Tracy\n");
		else
			printf("Teddy\n");
	}

	return 0;
}
