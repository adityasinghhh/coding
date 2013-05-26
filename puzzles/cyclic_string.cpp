#include<cstdio>
#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	string s, s1, s2;

	cin>>s1>>s2;

	s = s1+s1;

	if(s.find(s2))
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}
