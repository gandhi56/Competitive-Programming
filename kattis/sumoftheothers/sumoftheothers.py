import sys

for line in sys.stdin:
	values = [int(s) for s in line.split()]
	tot = sum(values)

	for v in values:
		if tot - v == v:
			print(v)
			break
	

