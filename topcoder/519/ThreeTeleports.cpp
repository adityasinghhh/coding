#include<vector>
#include<climits>
#include<string>
#include<iostream>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;
class ThreeTeleports
{
	public:
	long long int abs(long long int a)
	{
		return a > 0 ? a : -a;
	}

	long long int distance(int x1, int y1, int x2, int y2)
	{
		return abs(x1-x2)+abs(y1-y2);
	}

	bool mark[3];
	int p[100][5], _xHome, _yHome, _xMe, _yMe;
	long long int _mini;

	void f(int x, int y, long long int dist)
	{ 
		if(x == _xHome && y == _yHome)
		{
			if(_mini > dist)
				_mini = dist;

			return;
		}

		f(_xHome, _yHome, dist + distance(x, y, _xHome, _yHome));

		int i;      
		for(i=0; i<3; i++)
			if(!mark[i])
			{
				mark[i] = 1;
				f(p[i][2], p[i][3], dist + distance(x, y, p[i][0], p[i][1]) + 10);
				f(p[i][0], p[i][1], dist + distance(x, y, p[i][2], p[i][3]) + 10);          
				mark[i] = 0;            
			}
	}

	int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector<string> teleports)
	{
		_xHome = xHome;
		_yHome = yHome;
		_xMe = xMe;
		_yMe = yMe;

		int size = teleports.size(), l, i, j, x1, y1, x2, y2;
		string s;

		for(i=0; i<size; i++)
		{
			s = teleports[i]; 
			l = s.length();

			x1 = 0;
			j = 0;
			while(s[j] != ' ')
			{
				x1 = x1*10 + s[j++] - '0';
			}

			j++;
			y1 = 0;
			while(s[j] != ' ')
			{
				y1 = y1*10 + s[j++] - '0';
			}        

			j++;
			x2 = 0;
			while(s[j] != ' ')
			{
				x2 = x2*10 + s[j++] - '0';
			}

			j++;
			y2 = 0;
			while(s[j] != 0)
			{
				y2 = y2*10 + s[j++] - '0';
			}


			p[i][0] = x1;
			p[i][1] = y1;
			p[i][2] = x2;
			p[i][3] = y2;   
		}

		_mini = INT_MAX;

		f(xMe, yMe, 0);

		return _mini;
	}
};
