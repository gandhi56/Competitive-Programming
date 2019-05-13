import sys
from math import factorial as f

for line in sys.stdin:
	s = line.strip()
	denom = 1
	freq = {}
	for c in s:
		if c not in freq:
			freq[c] = 0
		freq[c] += 1

	val = f(len(s))
	for k,v in freq.items():
		val = val // f(v)

	print(val)
