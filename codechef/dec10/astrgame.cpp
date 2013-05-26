#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string s1[31];
int n;
bool flag1;

bool f(string s, int  z)
{
	cout<<z<<": "<<s<<endl;

	size_t found;
	int j, l = s.size();
	bool flag = 1, flag2 = 0;

	for(j=0; j<n; j++)
	{
		found = s.find(s1[j]);
//		cout<<s1[j]<<" "<<s1[j].size()<<endl;

		if(found != string::npos)
		{
			flag2 = 1;
			cout<<"Found: "<<(int)found<<"\n";

			cout<<"+"<<s1[j]<<": "<<s.substr(0, (int)found)<<endl;
			if((int)found != 0)
			{
				flag *= f(s.substr(0, (int)found), (z+1));
			}


//			if((int)found != l-s1[j].size())
//			{
				cout<<"-"<<s1[j]<<": "<<s.substr((int)found+s1[j].size(), l)<<endl;
				flag *= f(s.substr((int)found+s1[j].size(), l), (z+1));
//			}

			if(flag1 == 1)
				return flag;
		}
	}

	if(flag2 == 0)
	{
		flag1 = z;
	}

	return flag2;
}


int main()
{
	int no, i;
	string s;

	scanf("%d", &no);

	while(no--)
	{
		cin>>s;

		scanf("%d", &n);

		for(i=0; i<n; i++)
			cin>>s1[i];

		flag1 = 0;

		f(s, 0);

		if(flag1 == 0)
			printf("Teddy\n");
		else
			printf("Tracy\n");
	}

	return 0;
}
