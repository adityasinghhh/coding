#include<iostream>
using namespace std;
long long int s;
long long int get() 
{
	s = (s*5402147+54321)%10000001;
	return s%1000;
}

int main()
{
	long long int no, n, i, j, ret;
	bool f;
	cin>>no;

	while(no--)
	{
		cin>>n;

		int a[n+1];

		if(n == 1)
		{
			cin>>a[0];
			cout<<"Not enough observations\n";
			continue;
		}

		for(i=0; i<n; i++)
			cin>>a[i];

		f = 0;
		for(i=1; i<10000001; i++)
		{
			if(i%1000 == a[0])
			{
				s = i;
				for(j=1; j<n; j++)
				{
					ret = get();

					if(ret != a[j])
						break;
				}

				if(j == n)
				{
					f = true;
					break;
				}
			}
		}

		if(f)
		{
			for(i=0; i<10; i++)
			{
				ret = get();
				cout<<ret<<" ";
			}
			cout<<endl;
		}
		else
			cout<<"Wrong machine\n";

	}
}
