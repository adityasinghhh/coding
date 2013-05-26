
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
