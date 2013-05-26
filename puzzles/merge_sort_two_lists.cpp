#include<cstdio>
#include<iostream>
using namespace std;
class node
{
	public:
		int data;
		node *next;
};

int main()
{
	node *a = NULL, *b = NULL, *temp;

	int n, i, x;

	scanf("%d", &n);

	node **curr_a = &a;

	for(i=0; i<n; i++)
	{
		temp = new node;

		scanf("%d", &x);

		temp->data = x;
		temp->next = NULL;

		*curr_a = temp;
		curr_a = &(temp->next);
	}

	temp = a;

	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}		
	printf("\n");
	
	scanf("%d", &n);

	node **curr_b = &b;

	for(i=0; i<n; i++)
	{
		temp = new node;

		scanf("%d", &x);

		temp->data = x;
		temp->next = NULL;

		*curr_b = temp;
		curr_b = &(temp->next);
	}

	temp = b;

	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}		
	printf("\n");

	node *start, **curr_s;

	curr_a = &a;
	curr_b = &b;
	curr_s = &start;

	while(curr_a != NULL && curr_b != NULL)
	{
		if((*curr_a)->data > (*curr_b)->data)
		{
			curr_s = curr_a;
			curr_a = &((*curr_a)->next);
		}
		else
		{
			curr_s = curr_b;
			curr_b = &((*curr_b)->next);
		}
		curr_s = &((*curr_s)->next);
	}

	if(curr_a == NULL)
		curr_a = curr_b;
	else
		curr_b = curr_a;

	temp = start;

	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}		
	printf("\n");

}
