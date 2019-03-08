import sys

varList = {'+':'+', '-':'-', '=':'='}

def evaluate(exprList):
	val = exprList[0]
	for i in range(1, len(exprList)):
		if exprList[i] == '+':
			val = val + exprList[i+1]
		elif exprList[i] == '-':
			val = val - exprList[i+1]

	return val

for line in sys.stdin:
	instr = line.strip().split()
	if instr[0] == "def":
		varList[instr[1]] = int(instr[2])
	elif instr[0] == "calc":
		expr = instr[1:]
		solvable = True
		word = None
		for i in range(len(expr)):
			if expr[i] in varList.keys():
				expr[i] = varList[ expr[i] ]
			else:
				solvable = False
				word = expr[i]

		if not solvable:
			print(" ".join(instr[1:]), "unknown")
			continue

		# expr solvable here, every var replaced by its number
		val = evaluate(expr)

		solvable = False
		for k,v in varList.items():
			if v == val:
				word = k
				solvable = True
				break

		if solvable:
			print(" ".join(instr[1:]), word)
		else:
			print(" ".join(instr[1:]), "unknown")

	elif instr[0] == "clear":
		varList.clear()
