#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

string maxi;
int n, mark[20];
string s[20];
void f(int i, string s1)
{
	if(i == n)
	{
		if(s1 < maxi)
			maxi = s1;

//		cout<<s1<<endl;
		return;
	}

	for(int j=0; j<n; j++)
		if(mark[j] == 0)
		{
			mark[j] = 1;
			f(i+1, s1+s[j]);
			mark[j] = 0;
		}
}

int main()
{
	int no, i;
	char a[1000000];

	scanf("%d", &no);
	while(no--)
	{
		scanf("%d", &n);

		string s1 = (string)"";

		for(i=0; i<n; i++)
		{
			mark[i] = 0;
			scanf("%s", a);

			s[i] = (string)a;
		}

		maxi = (string)"zzzzzzzzzzzzzzzzzzzzz";
		f(0, s1);

		cout<<maxi<<endl;
	}
	return 0;
}
