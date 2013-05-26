a = []
a.append(0);
a.append(1);
a.append(3);

for i in range(3, 50):
	if i&1:
		a.append(a[i-1]+a[i-2]+1);
	else:
		a.append(2*a[i-1]+1);

print a;
