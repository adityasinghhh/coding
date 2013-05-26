a=[0.0];j=1.0
while j<20000001:a.append(a[-1]-1/j);j+=2;a.append(a[-1]+1/j);j+=2
t=input()
while t:print'%.15f'%a[input()];t-=1
