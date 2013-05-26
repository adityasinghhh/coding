#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
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

#define N 10000001
int primes[N], z;
int prime[N];
#define gP(n) (n==2||(n&1)&&prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))
void sieve()
{
        memset( prime, -1, sizeof( prime ) );

        int i;
        int sqrtN = (  int )sqrt( ( double )N ) + 1;
        for( i = 3; i < sqrtN; i += 2 ) if( gP( i ) )
        {
                int i2 = i + i;
                for(  int j = i * i; j < N; j += i2 ) rP( j );
        }
}

int main()
{
        sieve();

        int i;

        z = 0;

        for(i=2; i<N; i++)
                if(gP(i) > 0)
                        primes[z++] = i;

        InitFASTIO();

        int no = input(), n, s, x, c, f;

        while(no--)
        {
                n = input();

                if(n == 1)
                {
                        output(0, 1);
                        continue;
                }


                if(gP(n) > 0)
                {
                        output(1, 1);
                        continue;
                }

                i = 0;
                s = 1;
                x = n;
                while(x != 1)
                {
                        while(x%primes[i])
                                i++;

                        c = 0;
                        f = 1;
                        while(!(x%primes[i]))
                        {
                                x /= primes[i];
                                f *= primes[i];
                                c++;
                        }

                        s *= (f*primes[i]-1)/(primes[i]-1);
                        i++;
                }

                output(s-n, 1);
        }

        FlushFASTIO();

        return 0;
}


