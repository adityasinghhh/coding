f = open(raw_input(), 'r');
lines = f.readlines();
f.close();
for line in lines:
	line = line[:len(line)-1];

	print line, len(line);
