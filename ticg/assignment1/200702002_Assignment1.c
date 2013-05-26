#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
//#define max 1<<5;

struct data
{
	int v;
	struct data *parent,*left,*right;
	int level,index;
	int *mini;
	char *mini_c;
	int l_mini;
	int color[26];
};

struct data **tree;

struct data *temp,*demp, *chemp;

int main()
{
/*	int no, i, j, k, m, n, r, o, ii, x,y,z;
	double l;
	int max, fix;
	int p;
*/
	int no, max, maxi, p, i, j, fix, k, ii, m, z, t, a, b, i_a, i_b, c, child_index, left, right;
	double l;
	char ch;

	scanf("%d", &no);

	while(no--)
	{
		scanf("%d", &max);

		maxi = max;
		if(max&(max-1))
		{
			p = 0;
			while(max)
			{
				max /= 2;
				p++;
			}

			max = 1<<p;
		}

		int values[max+1];
		char colors[max+1];

		for(i=0; i<maxi; i++)
			scanf("%d", &values[i]);

		for(;i<max; i++)
			values[i] = INT_MAX;

		for(i=0; i<maxi; i++)
			while((colors[i] = getchar()) == ' ' || colors[i] == '\n');

		for(;i<max; i++)
			colors[i] = '-';

/*		printf("Values: ");
		for(i=0; i<max; i++)
			printf("%d ", values[i]);
		printf("\n");
		
		printf("Colors: ");
		for(i=0; i<max; i++)
			printf("%c ", colors[i]);
		printf("\n");
*/
		for(i=0; i<max; i++)
			for(j=i+1; j<max; j++)
				if(values[i] > values[j])
				{
					t = values[i];
					values[i] = values[j];
					values[j] = t;
					t = colors[i];
					colors[i] = colors[j];
					colors[j] = t;
				}

/*		printf("Values: ");
		for(i=0; i<max; i++)
			printf("%d ", values[i]);
		printf("\n");
		
		printf("Colors: ");
		for(i=0; i<max; i++)
			printf("%c ", colors[i]);
		printf("\n");
*/
		fix=max; 
		l=max;

		k=log2(l);

		tree= malloc((k+1)*sizeof(struct data*));

		for(i=k;i>-1;i--)
			tree[i]=malloc(sizeof(struct data)*(1<<k));

		for(j=0;j<(1<<k);j++)
		{
			demp=&tree[k][j];
			demp->mini=malloc(sizeof(int)*2);
			demp->mini_c=malloc(sizeof(char)*2);
			demp->mini[0]=demp->v=values[j];
			demp->mini[1]=demp->v=-1;
			demp->mini_c[0]=demp->v=colors[j];
			demp->level=k;
			demp->index=j;

			for(ii=0; ii<26; ii++)
				demp->color[ii] = 0;
		}

		for (i=k;i>0;i--)
		{
			for(j=0;j<(1<<i);j++)
			{
				demp=&tree[i][j];
				demp->level=i;
				demp->index=j;	  
			}
		}

		for(i=k;i>0;i--)
		{
			for(j=0;j<(1<<i);j=j+2)
			{

				temp=&tree[i-1][j/2];
				demp=&tree[i][j];
				chemp=&tree[i][j+1];
				demp->parent=chemp->parent=temp;
				temp->left=demp;
				temp->right=chemp;   
				temp->mini=malloc(sizeof(int)*(1+fix/(1<<temp->level))); 
				temp->mini_c=malloc(sizeof(char)*(1+fix/(1<<temp->level))); 

				for(ii=0; ii<26; ii++)
					demp->color[ii] = 0;
			}
		}
		
		for(i=0;i<=k;i++)
		{
			m = fix/(1<<i);
			for(j=0; j<(1<<i); j++)
			{
				if(j%2)		/* right child, 'mini' stored in ascending order */
				{
					z = 0;
					for(ii=0; ii<(1<<(k-i)); ii++)
					{
						ch = colors[j*m + ii];
						if(ch >= 'a' && ch <= 'z' && !((&tree[i][j])->color[ch-'a']))
						{
							(&tree[i][j])->color[ch-'a'] = 1;
							(&tree[i][j])->mini[z] = values[j*m + ii];
							(&tree[i][j])->mini_c[z++] = ch;
						}
					}
					(&tree[i][j])->l_mini = z;
					(&tree[i][j])->mini[z++] = -1;
				}
				else		/* left child, 'mini' stored in descending order */
				{
					z = 0;
					for(ii=(1<<(k-i))-1; ii>=0; ii--)
					{
						ch = colors[j*m + ii];
						if(ch >= 'a' && ch <= 'z' && !((&tree[i][j])->color[ch-'a']))
						{
							(&tree[i][j])->color[ch-'a'] = 1;
							(&tree[i][j])->mini[z] = values[j*m + ii];
							(&tree[i][j])->mini_c[z++] = ch;
						}
					}
					(&tree[i][j])->l_mini = z;
					(&tree[i][j])->mini[z++] = -1;
				}
			}
		}
		
		for(i=0;i<=k;i++)
		{
			m = fix/(1<<i);

			for(j=0; j<(1<<i); j++)
			{
				temp = &tree[i][j];

				for(ii=0, z=0; ii<26; ii++)
					if(temp->color[ii])
					{
						//printf("[%d]%d:%c ", j, temp->mini[z], temp->mini_c[z]);
						z++;
					}
				//printf("\t");
			}
			//printf("\n");
		}

		scanf("%d %d", &a, &b);
		//printf("%d %d\n", a, b);

		if(a > b)
		{
			t = a;
			a = b;
			b = t;
		}

		i_a = 0;
		while(values[i_a] < a)
			i_a++;
		
		i_b = max-1;
		while(values[i_b] > b)
			i_b--;

		//printf("%d:%d %d:%d\n", i_a, values[i_a], i_b, values[i_b]);
		
		t = 1;
		while(i_a/(1<<t) != i_b/(1<<t))
			t++;

		//printf("%d %d\n", k-t, i_a/(1<<t));

		child_index = k-t+1;
		left = 2*(i_a/(1<<t));
		right = left+1;
			
		int color[26] = {0};

/*		printf("Child Index: %d\n", child_index);
		printf("Left Child: %d\n", left);
		printf("Right Child: %d\n", right);
*/
		c = 0;
		i = 0;
		while((&tree[child_index][left])->mini[i] >= values[i_a])
		{
			if(!color[(&tree[child_index][left])->mini_c[i]-'a'])
			{
				c++;
				color[(&tree[child_index][left])->mini_c[i]-'a'] = 1;
				//printf("%d ", (&tree[child_index][left])->mini[i]);
			}
			i++;
		}

		i = 0;
		while((&tree[child_index][right])->mini[i] <= values[i_b])
		{
			if(!color[(&tree[child_index][right])->mini_c[i]-'a'])
			{
				c++;
				color[(&tree[child_index][right])->mini_c[i]-'a'] = 1;
				//printf("%d ", (&tree[child_index][right])->mini[i]);
			}
			i++;
		}
		//printf("\n");

		printf("%d\n", c);
	}
}

