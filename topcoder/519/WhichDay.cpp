#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class WhichDay
{
	public:
	string getDay(vector <string> v)
	{
		sort(v.begin(), v.end());

		if(v[0] != "Friday")
			return "Friday";
		if(v[1] != "Monday")
			return "Monday";
		if(v[2] != "Saturday")
			return "Saturday";
		if(v[3] != "Sunday")
			return "Sunday";
		if(v[4] != "Thursday")
			return "Thursday";
		if(v[5] != "Tuesday")
			return "Tuesday";

		return "Wednesday";        
	}
};
