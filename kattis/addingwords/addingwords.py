import sys

v = dict()

for line in sys.stdin:
	exp = line.split()
	if exp[0] == 'def':
		if exp[1] in v.keys():
			del v[exp[1]]
		v[exp[1]] = int(exp[2])
	elif exp[0] == 'calc':
		# check if all variables are defined
		ok = True
		for i in range(1, len(exp), 2):
			if exp[i] not in v.keys():
				print(exp[i], 'not found')
				ok = False
				break
		if not ok:
			print(' '.join(exp[1:]) + ' unknown')
			continue

		# vars defined, compute the value
		print(' '.join(exp[1:-1]))
		print(eval(' '.join(exp[1:-1]), v))

	elif exp[0] == 'clear':
		v.clear()


