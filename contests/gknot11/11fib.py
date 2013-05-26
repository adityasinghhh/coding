a = [];

a.append(1);
a.append(2);
a.append(3);

print 1, 2;
print 2, 3;

for i in range(3, 81):
	a.append(a[i-2]+a[i-1]);
	print i, a[i];

