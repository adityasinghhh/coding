import math;

a = float(2341276.0);
b = float(34374833.0);
c = float(18278172.0);
d = float(17267343.0);

s = float((a+b+c+d)/2.0);

area = float(math.sqrt((s-a)*(s-b)*(s-c)*(s-d)));

print '%.16f' % area;


