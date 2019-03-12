from sys import stdin

varList = dict()

for line in stdin:
	exprList = line.strip().split()
	
	if exprList[0] == 'def':
		varList[exprList[1]] = int(exprList[2])
	elif exprList[0] == 'calc':
		ok = True
		for i in range(1, len(exprList), 2):
			# check if var is defined
			if exprList[i] not in varList.keys():
				ok = False
				break

		if not ok:
			print(' '.join(exprList[1:]), 'unknown')
			continue

		# all variables defined
		print(eval(' '.join(exprList[1:len(exprList)-1]), varList))
	elif exprList[0] == 'clear':
		varList.clear()
