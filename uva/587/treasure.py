import sys

t = 1
for line in sys.stdin:
	if line.strip() == "END":
		break
	print("Map #{0}".format(t))
	t += 1
	s = line.strip().split(',')
	s[-1] = s[-1][:-1]

	curr = [0,0]
	for c in s:
		d = None
		k = None
		if c[-2] in 'NS':
			d = c[-2:]
			k = int(c[:-2])
		else:
			d = c[-1]
			k = int(c[:-1])
		if d == 'N':
			curr[1] += k
		elif d == 'S':
			curr[1] -= k
		elif d == 'W':
			curr[0] -= k
		elif d == 'E':
			curr[0] += k
		elif d == 'NW':
			a = (k/2)*(2**0.5)
			curr[0] -= a
			curr[1] += a
		elif d == 'SW':			
			a = (k/2)*(2**0.5)
			curr[0] -= a
			curr[1] -= a
		elif d == 'SE':			
			a = (k/2)*(2**0.5)
			curr[0] += a
			curr[1] -= a
		elif d == 'NE':			
			a = (k/2)*(2**0.5)
			curr[0] += a
			curr[1] += a
	print("The treasure is located at (%.3f,%.3f)." %(curr[0], curr[1]))
	print("The distance to the treasure is %.3f."%(curr[0]**2 + curr[1]**2)**0.5)
	print()
