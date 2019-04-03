import sys

for line in sys.stdin:
	p = line.strip()
	s = input().strip()

	i = 0
	while 1:
		i = s.find(p, i)
		if i == -1:
			break
		print(i, end=' ')
		i += len(p)
	print()
