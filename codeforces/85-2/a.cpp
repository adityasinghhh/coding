#include<string>
#include<cstdio>
using namespace std;
int main()
{
	char a[10000], b[10000];
	int i;
	scanf("%s", a);
	scanf("%s", b);

	for(i=0; a[i]; i++) {
		a[i] = tolower(a[i]);
		b[i] = tolower(b[i]);

		if(a[i] == b[i])
			continue;
		else if(a[i] < b[i]) {
			printf("-1\n");
			break;
		} else {      
			printf("1\n");
			break;
		}
	}

	if(!a[i])
		printf("0\n");

	return 0;
}
