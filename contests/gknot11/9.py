n = 1237940039285380274899124223;
#n = 20;

s = 0;
i = 1;
c = 0;

while i < n:
	s += i*i;
	i *= 2;
	c+=1;

print s;
