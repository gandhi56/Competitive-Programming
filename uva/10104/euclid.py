import sys

def gcd(a, b):
	if b == 0:
		return (a, 1, 0)
	d1, x1, y1 = gcd(b, a%b)
	return d1, y1, x1 - (a//b) * y1

for line in sys.stdin:
	a, b = map(int, line.split())
	g = gcd(a, b)
	print(g[1], g[2], g[0])
