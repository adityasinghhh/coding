#include<iostream>
#include<vector>
#define L long long
#define V vector<L>
#define P push_back
using namespace std;L C=1e9+7;V M(V A,L p){if(p==1)return A;else if(p==2){V R;R.P(A[0]*A[0]+A[1]*A[2]);R.P(A[0]*A[1]+A[1]*A[3]);R.P(A[2]*A[0]+A[3]*A[2]);R.P(A[2]*A[1]+A[3]*A[3]);for(int i=0;i<4;++i)R[i]%=C;return R;}else if(p&1){V B=M(A,p-1),R;R.P(A[0]*B[0]+A[1]*B[2]);R.P(A[0]*B[1]+A[1]*B[3]);R.P(A[2]*B[0]+A[3]*B[2]);R.P(A[2]*B[1]+A[3]*B[3]);for(int i=0;i<4;++i)R[i]%=C;return R;}return M(M(A,p/2),2);}main(){L N;cin>>N;while(cin>>N)if(N<4)cout<<"0\n";else if(N==4)cout<<"2\n";else if(N==5)cout<<"5\n";else{V A;A.P(1),A.P(1),A.P(1),A.P(0);V c=M(A,N-3);cout<<(2*(c[0]+c[1]))%C<<endl;}return 0;}
