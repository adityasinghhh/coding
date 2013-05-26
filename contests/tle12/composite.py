def prime(n):
	if n == 0 or n == 1:
		return False;
	i = 2;
	while i*i <= n:
		if n%i == 0:
			return False;
		i += 1;
	return True;

f = open('composite.c','r');
lines = f.readlines();
for line in lines:
	line = line[:len(line)-1];
	a = '';
	for i in range(len(line)):
		if(not prime(i)):
			a += line[i];
	print a;
