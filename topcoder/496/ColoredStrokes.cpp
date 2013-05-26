#include<string>
#include<cstring>
#include<vector>
using namespace std;
class ColoredStrokes
{
	int getLeast(vector <string> picture)
	{
		int W = picture.size(), H = picture[i].length();

		int i, j, c=0;
		for(i=0; i<W; i++)
		{	
			flag = 0;
			j = 0;
			while(j != H)
			{
				while(picture[i][j] == '.')
					j++;

				if(picture[i][j] == 'R' || picture[i][j] == 'G')
				{
					c++;
					while(picture[i][j] == 'R' || picture[i][j] == 'G')
					{
						if(picture[i][j] == 'G')
							picture[i][j] = 'B';
						j++;
					}
				}
			}
		}

		for(i=0; i<H; i++)
		{	
			flag = 0;
			j = 0;
			while(j != W)
			{
				while(picture[j][i] == '.')
					j++;

				if(picture[j][i] == 'B')
				{
					c++;
					while(picture[j][i] == 'B')
					{
						j++;
					}
				}
			}
		}

		return c;
	}
};
