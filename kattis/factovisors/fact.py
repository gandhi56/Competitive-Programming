import sys
from math import factorial as f

for line in sys.stdin:
	n, m = map(int, line.split())
	if f(n) % m == 0:
		print(m, "divides", str(n)+"!")
	else:
		print(m, "does not divide", str(n)+"!")

