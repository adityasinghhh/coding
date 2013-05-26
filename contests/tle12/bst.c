typedef struct
{
		int D;
		N *L, *R;
}N;
N*r = NULL;N*I(N*t, int x){if(!t){t=(N*)malloc(sizeof N);t->D=x;t->L=t->R=NULL;}else if(t->D>x)t->L=I(t->L,x);else t->R=I(t->R,x);return t;}

void f()
{
	VVI v; VI temp; v.PB(temp);
	queue<N*> q;
	q.push(r); q.push(NULL);
	int i = 0;
	while(!q.empty())
	{
		N *t = q.front(); q.pop();

		if(!t)
		{
			if(q.empty()) { break; }
			++i; VI temp; v.PB(temp);
			q.push(NULL);
			continue;
		}

		v[i].PB(t->D);
		if(t->L)
		{
			q.push(t->L);
		}
		if(t->R)
		{
			q.push(t->R);
		}
	}

	REPD(i,v.size())
	{
		REPD(j,v[i].size())
		{
			printf("%d ", v[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int N = SI;
	while(N--){int x = SI; r = I(r, x); }

	f();
	
	return 0;
}
