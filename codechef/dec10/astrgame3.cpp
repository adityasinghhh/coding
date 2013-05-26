#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
map<vector<pair<int, int> >, int> m;
int n;
char a[100], s1[50][50];
int s1_size[50];

int f_tracy(vector<pair<int, int> >);

int f_teddy(vector<pair<int, int> > v)
{
//	int val = m[v];
	
//	if(val != 0)
//		return val;

	int l = v.size(), i, j, len, ii, jj, k, kk, b, e;
vector<pair<int, int> > v1;

	for(i=0; i<l; i++)
	{
		b = v[i].first;
		e = v[i].second;

		for(j=0; j<n; j++)
		{
			if(b-e+1 < s1_size[j])
				continue;

			for(k=b; k<=e; k++)
			{
				for(kk=k, jj=0; jj<s1_size[j]; kk++, jj++)
					if(a[kk] != s1[j][jj])
						break;

				if(jj == s1_size[j])
					break;
			}

			if(k == e+1)
				continue;
			
			v1 = v;
			v1.erase(v1.begin()+i);
			
			if(kk != b+s1_size[j])
				v1.push_back(make_pair(b, k-1));
			if(kk != e+1)
				v1.push_back(make_pair(kk, e));

//			sort(v1.begin(), v1.end());
			if(v1.empty() || f_tracy(v1) == 1)
			{
//				m[v] = 1;
				return 1;
			}
		}
	}

//	m[v] = -1;
	return -1;
}

int f_tracy(vector<pair<int, int> > v)
{
//	int val = m[v];
	
//	if(val != 0)
//		return -val;

	int l = v.size(), i, j, len, ii, jj, k, kk, b, e;
	vector<pair<int, int> > v1;

	for(i=0; i<l; i++)
	{
		b = v[i].first;
		e = v[i].second;

		for(j=0; j<n; j++)
		{
			if(b-e+1 < s1_size[j])
				continue;

			for(k=b; k<=e; k++)
			{
				for(kk=k, jj=0; jj<s1_size[j]; kk++, jj++)
					if(a[kk] != s1[j][jj])
						break;

				if(jj == s1_size[j])
					break;
			}

			if(k == e+1)
				continue;

			v1 = v;
			v1.erase(v1.begin()+i);
			
			if(kk != b+s1_size[j])
				v1.push_back(make_pair(b, k-1));
			if(kk != e+1)
				v1.push_back(make_pair(kk, e));

//			sort(v1.begin(), v1.end());
			if(v1.empty() || f_teddy(v1) == -1)
			{
//				m[v] = 1;
				return -1;
			}
		}
	}

//	m[v] = -1;
	return 1;
}


int main()
{
	int no, i, j, l, k, jj;

	scanf("%d", &no);
	while(no--)
	{
//		m.clear();
		scanf("%s", a);
		l = strlen(a);

		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", s1[i]);
			s1_size[i] = strlen(s1[i]);

			for(j=0; j<l; j++)
			{
				for(jj = j, k = 0; k<s1_size[i]; k++, jj++)
					if(a[jj] != s1[i][k])
						break;

				if(k == s1_size[i])
					break;
			}

			if(j == l)
			{
				i--;
				n--;
			}
		}

		vector<pair<int, int> > v;
		v.push_back(make_pair(0, l-1));

		if(f_teddy(v) == -1)
			printf("Tracy\n");
		else
			printf("Teddy\n");
	}

	return 0;
}
