#include<cstdio>
#include<cmath>
int main()
{
	char a[10000000];
	double f = (1.0 - logl((double)2.0) + (double)M_PI / coshl(sqrtl((double)3.0)*(double)M_PI/(double)2.0))/(double)3.0;

	sprintf(a, "%.101lf", f);
	printf("%s\n", a);
}
