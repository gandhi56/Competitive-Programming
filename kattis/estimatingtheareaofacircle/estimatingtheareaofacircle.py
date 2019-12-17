from math import pi

while 1:
	r, m, c = map(str, input().split())
	r, m, c = float(r), int(m), int(c)
	if r == 0 and m == 0 and c == 0:
		break
	print('%.9f %.6f' %(pi*r*r, 4*r*r*(c/m)))
