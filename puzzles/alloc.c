#include<stdio.h>
#include<malloc.h>
int main()
{
	int *a = (int*)calloc(10, sizeof(int));
	int i;
	for(i=0; i<10; i++)
		printf("%d ", a[i]);
	printf("\n");
	
	int *b = (int*)malloc(10 * sizeof(int));
	for(i=0; i<10; i++)
	{
		b[i] = i;
		printf("%d ", b[i]);
	}
	printf("\n");
	
	b = (int*)realloc(b, 20* sizeof(int));
	for(i=0; i<400; i++)
		printf("%d ", b[i]);
	printf("\n");
}
