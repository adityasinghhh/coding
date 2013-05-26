flag = 0;
while True:
	try:
		x = raw_input();
	
		if x == '':
			print x;
			continue;
	
		if flag == 0:
			print x;
			flag = 1;
		else:
			a = '';
			if ord(x[0]) > 90:
				a += x.strip();
			else:
				a += '    ' + x;
			print a;
				
	except:
		break;
