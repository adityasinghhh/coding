#include<iostream>
#include<queue>
#include<vector>
#define P(a) push_back(a)
using namespace std;class N{public:int D;N*L,*R;};N*I(N*t,int x){if(!t)t=new N,t->D=x,t->L=t->R=0;else if(t->D>x)t->L=I(t->L,x);else t->R=I(t->R,x);return t;}main(){N*t=0;int i,j;cin>>j;while(cin>>j)t=I(t,j);vector<int>v;queue<N*>q;q.push(t);q.push(0);while(1){t=q.front();q.pop();if(!t){if(q.empty())break;v.P(0);q.push(0);continue;}v.P(t->D);if(t->L)q.push(t->L);if(t->R)q.push(t->R);}i=v.size()-1;while(i>=0){j=i;while(i>=0&&v[i])--i;while(j>i)cout<<v[j--]<<" ";--i;cout<<endl;}return 0;}
