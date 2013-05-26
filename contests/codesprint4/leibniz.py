a=[0.0];j=1.0
while j<20000001:a.append(a[-1]+pow(-1,int(j)/2)/j);j+=2;
t=input()
while t:print'%.15f'%a[input()];t-=1
