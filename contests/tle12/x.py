s = raw_input();
f = open(s,'r');
lines = f.readlines();
a = ''
for line in lines:
	line = line[:len(line)-1];
	a += line + '\n';
print a;
