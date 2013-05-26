#include<stdio.h>
#include<string.h>
int Hash(char*a,int i, int j){int h=0,m=1009,k;for(k=i;k<j;k++){h=(h*256+a[k])%m;}return h;}
main(l,left,right){char b[10001],a[10001];strcpy(b,"");while(scanf("%s",a)!=EOF)strcat(b,a);l=strlen(b);if(l%2)puts("No");else{left=Hash(b,0,l/2);right=Hash(b,l/2,l);if(left==right)puts("Yes");else puts("No");}}
