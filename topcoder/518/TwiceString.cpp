#include<string>

class TwiceString
{
	public:
	string getShortest(string s)
	{
		int l = s.length(), i, ii, j;
		
		for(i=1; i<l; i++)
		{
			ii = i;
			for(j=0; ii<l; j++, ii++)
			{
				if(s[ii] != s[j])
					break;
			}			
			
			if(ii == l)
			{
				break;
			}
		}
		
		if(i == l)
			return 2*l;
			
		return 2*l-ii+i;		
	}
};
//Powered by [KawigiEdit] 2.0!
