f = open('wonder-woman.txt','r');
lines = f.readlines();
for line in lines:
	line = line[:len(line)-1];
	print 'printf("' + line + '");'
