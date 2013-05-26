f = [0,1,1];

sum = 0;
for i in xrange(3,65):
	f.append(f[i-1] + f[i-2]);
	t = 0; t1 = f[i];
	while(t1):
		t += t1%10;
		t1 /= 10;
	if(t == i): 
		sum += f[i]
		print i, t

print sum
