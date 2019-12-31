import sys

def super(x, y):
	return (x == 1 and y == 2) or (x == 2 and y == 1)

for line in sys.stdin:
	a, b, c, d = map(int, line.split())
	if a == 0 and  b == 0 and c == 0 and d == 0:
		break
	
	if super(a, b) and super(c, d):
		print('Tie.')
		continue
	elif super(a, b) and not super(c, d):
		print('Player 1 wins.')
		continue
	elif not super(a, b) and super(c, d):
		print('Player 2 wins.')
		continue

	if a == b and c != d:
		print('Player 1 wins.')
		continue
	elif a != b and c == d:
		print('Player 2 wins.')
		continue
	elif a == b and c == d:
		if a > c:
			print('Player 1 wins.')
		elif a < c:
			print('Player 2 wins.')
		else:
			print('Tie.')
		continue
	
	if b > a:
		a, b = b, a
	if d > c:
		c, d = d, c
	
	num1 = str(a)+str(b)
	num2 = str(c)+str(d)
	if num1 > num2:
		print('Player 1 wins.')
	elif num1 < num2:
		print('Player 2 wins.')
	else:
		print('Tie.')
