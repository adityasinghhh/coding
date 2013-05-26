t=input()
while t:
	t-=1;n=2.0*input()-1;x=0.0
	while n>0:x+=(-1)**(int(n)/2)/n;n-=2
	print'%.15f'%x
