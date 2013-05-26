main(i)
{
	unsigned char a[999];
	while(scanf("%s",a)!=-1)
	{
		i=0;
		while(a[i])
		{
//			printf("%d: %c to ",i,a[i]);
			if(i&1)
			{
				if(a[i]<='9'){a[i]-=i%10;while(a[i]<'0'){a[i]+=10;}}
				else if(a[i]<='Z'){a[i]-=i%26;while(a[i]<'A'){a[i]+=26;}}
				else{a[i]-=i%26;while(a[i]<'a'){a[i]+=26;}}
			}
			else
			{
				if(a[i]<='9'){a[i]+=i%10;while(a[i]>'9'){a[i]-=10;}}
				else if(a[i]<='Z'){a[i]+=i%26;while(a[i]>'Z'){a[i]-=26;}}
				else{a[i]+=i%26;;while(a[i]>'z'){a[i]-=26;}}
			}
//			printf("%c\n",a[i]);
			++i;
		}
		printf("%s\n",a);
	}
	return 0;
}
