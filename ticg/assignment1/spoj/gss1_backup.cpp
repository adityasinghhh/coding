#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<climits>
char *ipos, *opos, InpFile[20000000], OutFile[20000000], DIP[20];
inline int input(int flag=0) {

	while(*ipos <= 32) ++ipos;
	if ( flag  ) return (*ipos++ - '0'); /* For getting Boolean Characters */
	int x=0, neg = 0;char c;
	while( true ) {
		c=*ipos++; if(c == '-') neg = 1;
		else {
			if (c<=32) return neg?-x:x;
			x=(x<<1)+(x<<3)+c-'0';
		}
	}
}
inline void output(int x,int flag) {
	int y,dig=0;
	while (x||!dig) { y=x/10;DIP[dig++]=x-((y << 3) + (y << 1))+'0';x=y;}
	while (dig--) *opos++=DIP[dig];
	*opos++= flag ? '\n' : ' ';
}
inline void InitFASTIO() {
	ipos = InpFile; opos = OutFile;
	fread_unlocked(InpFile,20000000,1,stdin);
}
inline void FlushFASTIO() {
	fwrite_unlocked(OutFile,opos-OutFile,1,stdout);
}

//#define max 1<<5;

class data
{
	public:
		data *parent,*left,*right;
		long long int *mini;
		int level;
};

data **tree;

data *temp,*demp, *chemp;

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

//	scanf("%d", &max);
	InitFASTIO();

	max = input();

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
		values[i] = input();
//		scanf("%d", &values[i]);

	for(;i<max; i++)
		values[i] = INT_MIN;

	fix=max; 
	l=max;

	k=log2(l);

	tree = new data*[k+1];

	for(i=k;i>-1;i--)
		tree[i]=new data[(1<<k)];

	for(j=0;j<(1<<k);j++)
	{
		demp=&tree[k][j];
		demp->mini=new long long int[2];
		demp->level=k;
	}

	for (i=k;i>0;i--)
	{
		for(j=0;j<(1<<i);j++)
		{
			demp=&tree[i][j];
			demp->level=i;
		}
	}


	for(i=k;i>0;i--)
	{
		for(j=0;j<(1<<i);j=j+2)
		{

			temp=&tree[i-1][j/2];
			temp->mini=new long long int[1+fix/(1<<temp->level)]; 
		}
	}

	//printf("here\n");

	for(i=0;i<=k;i++)
	{
		m = fix/(1<<i);
		for(j=0; j<(1<<i); j++)
		{
			(&tree[i][j])->mini[0] = values[j*m];
			for(ii=1; ii<(1<<(k-i)); ii++)
				(&tree[i][j])->mini[ii] = values[j*m + ii] + (&tree[i][j])->mini[ii -1] > (&tree[i][j])->mini[ii -1] ? values[j*m + ii] + (&tree[i][j])->mini[ii -1] : (&tree[i][j])->mini[ii -1];
			for(ii=0; ii<(1<<(k-i)); ii++)
				printf("%d ", (&tree[i][j])->mini[ii]);
			printf("\t");
		}
		printf("\n");
	}

	int num;

	num = input();
//	scanf("%d", &num);

	while(num--)
	{
		a = input();
		b = input();
//		scanf("%d %d", &a, &b);

		/*			if(a > b)
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
					*/
		i_a = a-1;
		i_b = b-1;
		
/*		for(i = i_a; i<=i_b; i++)
			printf("%d ", values[i]);
		printf("\n");
*/		
		t = 1;
		while(i_a/(1<<t) != i_b/(1<<t))
			t++;

		child_index = k-t+1;
		int child_index1 = k-child_index;
		left = 2*(i_a/(1<<t));
		right = left+1;

/*		printf("Child Index: %d\n", child_index);
		printf("Left: %d\n", left);
		printf("Right: %d\n", right);

		printf("%d %d\n", (1<<child_index1)-1, i_b%(1<<child_index1));
		printf("%d %d\n", (&tree[child_index][left])->mini[(1<<child_index1)-1], (&tree[child_index][right])->mini[i_b%(1<<child_index1)]);
*/	
//		printf("%d\n", (&tree[child_index][left])->mini[(1<<child_index1)-1] > (&tree[child_index][right])->mini[i_b%(1<<child_index1)] ? (&tree[child_index][left])->mini[(1<<child_index1)-1] : (&tree[child_index][right])->mini[i_b%(1<<child_index1)]);

		int sum = (&tree[child_index][left])->mini[(1<<child_index1)-1] + (&tree[child_index][right])->mini[i_b%(1<<child_index1)];
		int sum_lr;
		
		if((&tree[child_index][left])->mini[(1<<child_index1)-1] > (&tree[child_index][right])->mini[i_b%(1<<child_index1)])
			sum_lr = (&tree[child_index][left])->mini[(1<<child_index1)-1];
		else
			sum_lr = (&tree[child_index][right])->mini[i_b%(1<<child_index1)];

		if(sum > sum_lr)
			output(sum, 1);
		else
			output(sum_lr, 1);
	}	

	FlushFASTIO();

	return 0;
}

