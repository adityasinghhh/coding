#include<sstream>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	double n;

	scanf("%lf", &n);

	string s;

	ostringstream convert;

	convert<<n;

	s = convert.str();
	

	printf("%s\n", s.c_str());

	istringstream convert1(s);

	convert1>>n;

	printf("%lf\n", n);

}
