#include<stdio.h>
#include<stdlib.h>
#define max 16;

struct data
{
 int v;
 struct data *parent,*left,*right;
 int level,index;
 int *mini;
};

struct data **tree;

struct data *temp,*demp, *chemp;

int main()
{
	int i,j,k,m,n,r,o;
        int x,y,z;
	double l;
        int fix=max; 
	l=max;

       k=log2(l);

   tree= malloc((k+1)*sizeof(struct data*));

   for(i=k;i>-1;i--)
	 tree[i]=malloc(sizeof(struct data)*(1<<k));

for(j=0;j<(1<<k);j++)
{
	demp=&tree[k][j];
	demp->mini=malloc(sizeof(int)*1);
	demp->mini[0]=demp->v=(1<<k)-j+1;
        demp->level=k;
	demp->index=j;


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
      temp->mini=malloc(sizeof(int)*(fix/(1<<temp->level))); 
  
  }



}

for(i=1;i<k;i++)
{
  for(j=0;j<(1<<i);j++)
  {    
	  temp=&tree[i][j];
	  m=fix/(1<<temp->level);
	  r=m*temp->index;
	  o=r+m;
          //x=0;
	  
	  printf("\n r= %d o=%d\n",r, o); 
	  if(temp->index%2==0)
	  { x=m-1;
	     for(y=o-1;y>r-1;y--)
	     {         
	       	     demp=&tree[k][y];
		     temp->mini[x--]=demp->v;	     
                             
	     
	     }      
	  
	  
	  }
	  
     else
     {
          x=0;
	  for(y=r;y<o;y++)
	  {
		  demp=&tree[k][y];
		  temp->mini[x++]=demp->v;
          }

      }	     
  
  
  
  
  }


}


for(i=1;i<k;i++)
{
	for(j=0;j<(1<<i);j++)
	{
	   temp=&tree[i][j];
           
	   for(x=0;x<fix/(1<<temp->level);x++)
		   printf("%d ", temp->mini[x]);

	   printf("\n");
	
	}


}




}

