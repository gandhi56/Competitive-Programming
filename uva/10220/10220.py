import sys
from math import factorial as f

def digit_sum(n):
	t = 0
	while n:
		t += (n%10)
		n //= 10

	return t

for line in sys.stdin:
	n = int(line)
	print(digit_sum(f(n)))
