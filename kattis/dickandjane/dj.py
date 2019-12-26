import sys

for line in sys.stdin:
	s, p, y, j = map(int, line.strip().split())

	solved = False

	a = p
	while a <= p + 1 and not solved:
		
		b = y
		while b <= y + 1 and not solved:
			
			x3 = 12 + j - a - b
			if x3 >= 0 and x3 % 3 == 0:
				x3 //= 3
				x2 = x3 + a
				x1 = x3 + b
				if ((x1 - x2 == s or x1 - x2 == s + 1) and (x2 - x3 == p or x2 - x3 == p + 1) and (x1 - x3 == y or x1 - x3 == y + 1)):
					print(x1, x2, x3)
					solved = True
			
			b += 1
		
		a += 1
