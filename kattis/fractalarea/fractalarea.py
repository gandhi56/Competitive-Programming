from math import pi

def area(r, n):
	area = pi*r*r
	count = 4
	r /= 2
	for i in range(1, n):
		area += count*pi*r*r
		r /= 2
		count *= 3
	return area

t = int(input())
for _ in range(t):
	r, i = map(int, input().split())
	print('%.20f' %(area(r, i)))
