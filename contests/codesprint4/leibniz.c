double a[10000001],j;main(i){i=j=1;while(i<10000001){a[i++]=a[i-1]+(i&1?1:-1)/j;j+=2;}scanf("%d",&i);while(scanf("%d",&i)!=-1)printf("%.15lf\n",a[i]);}
