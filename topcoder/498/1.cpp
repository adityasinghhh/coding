#include<cstdio>
#include<vector>
#include<string>
using namespace std;
class FoxSequence
{
	public:
		string isValid(vector<int> seq)
		{
			string yes = string("yes"), no = string("no");

			int size = seq.size(), i=1;

			diff = a[1]-a[0];
			while(i!=size && a[i]>a[i-1])
			{
				if(a[i]-a[i-1] != diff)
					return no;
				i++;
			}

			if(i == size)
				return no;

			diff = a[i]-a[i-1];
			while(i!=size && a[i]<a[i-1])
			{		
				if(a[i]-a[i-1] != diff)
					return no;
				i++;
			}

			if(i == size)
				return no;

			while(i!=size && a[i] == a[i-1])
				i++;

			if(i == size)
				return no;

			diff = a[i]-a[i-1];
			while(i!=size && a[i]>a[i-1])
			{
				if(a[i]-a[i-1] != diff)
					return no;
				i++;
			}

			if(i == size)
				return no;

			diff = a[i]-a[i-1];
			while(i!=size && a[i]<a[i-1])
			{		
				if(a[i]-a[i-1] != diff)
					return no;
				i++;
			}

			return yes;		
		}
};

main()
{
}
