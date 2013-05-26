#include<iostream>
#include<queue>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	int no, n, i, v, j, l;
	string s;
	size_t found;

	scanf("%d", &no);

	while(no--)
	{
		cin>>s;

		l = s.size();

		scanf("%d", &n);

		string s1[n+1];

		for(i=0; i<n; i++)
			cin>>s1[i];

		queue<string> q;
		queue<int> q1;

		q.push(s);
		q1.push(0);

		while(!q.empty())
		{
			cout<<"Front: "<<q1.front()<<". "<<q.front()<<"\tBack: "<<q1.back()<<". "<<q.back()<<"\n";
			s = q.front();
			q.pop();
			v = q1.front();
			q1.pop();


			if(s.empty())
				break;		

			for(i=0; i<n; i++)
			{
				found = s.find(s1[i]);

				if(found != string::npos)
				{
		//	printf("here\n");
					if((int)found != 0)
					{
		//	printf("here\n");
						q.push(s.substr(0, (int)found));
						q1.push((v+1)%2);
					}
		//	printf("there\n");

					if((int)found != l-s1[i].size())
					{
		//	printf("there\n");
						q.push(s.substr((int)found+s1[i].size(), l));
						q1.push((v+1)%2);
					}
				}
			}
		//	printf("here\n");
		}

		if(v == 0)
			printf("Tracy\n");
		else
			printf("Teddy\n");
	}
}

