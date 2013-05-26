s = raw_input();
f = open(s, 'r');
lines = f.readlines();
l = len(lines);
for i in range(l-1,-1,-1):
	print lines[i][:len(lines[i])-1];
