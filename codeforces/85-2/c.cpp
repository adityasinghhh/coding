#include<cstdio>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	long long int n, x, y;
	cin>>n>>x>>y;

	long long int maxi = (y-n+1)*(y-n+1)+n-1;

	if(x > maxi)
		printf("-1\n");
	else
	{
		long long int one = 1;
		for(long long int i=0; i<n-1; i++)
			cout<<one<<endl;
		cout<<y-n+1<<endl;
	}

	return 0;
}
