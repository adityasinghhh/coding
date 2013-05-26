import math;
p = (1.0+math.sqrt(5.0))/2.0;

i = 0.0;
c = 0;
while True:
	x = math.floor(p*i);
	y = math.floor(p*p*i);

	if y > 100000000:
		break

	c+=1;

	i += 1.0;

print c;
