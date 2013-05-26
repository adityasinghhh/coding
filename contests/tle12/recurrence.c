#define LL long long
LL C=1000000007;
LL*mypow(LL*A,LL p)
{
	int i;
	if(p==0){LL ret[]={1,0,0,1};return ret;}
	else if(p == 1){return A;}
	else if(p == 2){LL*ret=(LL*)malloc(sizeof(ret));ret[0]=A[0]*A[0]+A[1]*A[2];ret[1]=A[0]*A[1]+A[1]*A[3];ret[2]=A[2]*A[0]+A[3]*A[2];ret[3]=A[2]*A[1]+A[3]*A[3];for(i=0;i<4;++i){ret[i]%=C;}return ret;}
	else if(p&1)
	{
		LL*B=mypow(A,p-1),*ret=(LL*)malloc(sizeof(ret));ret[0]=A[0]*B[0]+A[1]*B[2];ret[1]=A[0]*B[1]+A[1]*B[3];ret[2]=A[2]*B[0]+A[3]*B[2];ret[3]=A[2]*B[1]+A[3]*B[3];for(i=0;i<4;++i){ret[i]%=C;}return ret;
	}
	return mypow(mypow(A,p/2),2);
}
main()
{
	long long N;scanf("%lld",&N);
	while(scanf("%lld",&N)!=-1)
	{
		if(N<4){printf("0\n");}else if(N==4){printf("2\n");}else if(N==5){printf("5\n");}
		else
		{
			LL A[]={1,1,1,0}, *c = mypow(A,N-2);
			printf("%lld\n",(2ll*(c[2]+c[3]))%C);
		}
	}
	return 0;
}
