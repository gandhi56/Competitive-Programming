import math, sys

def cantor(n, d):
	for _ in range(100):
		if n == 0 or n == d:
			return True
		if d < 3*n < 2*d:
			return False
		
		if 3*n <= d:
			n*= 3
		else:
			n = 3*n-2*d
			d *= 3
		g = math.gcd(n, d)
		n, d = n // g, d // g

	return True

for line in sys.stdin:
	line = line.strip()
	if line == 'END':
		break

	# convert number into fraction
	n, d = 0, 1
	inFrac = False
	for c in line:
		if c == '.':
			inFrac = True
		else:
			n *= 10
			n += int(c)
			if inFrac:
				d *= 10

	print('MEMBER' if cantor(n,d) else 'NON-MEMBER')
