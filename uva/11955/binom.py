



cdp = []
for i in range(51):
	cdp.append([])
	for j in range(51):
		cdp[i].append(-1)

def binomCoeff(n, k):
	if cdp[n][k] == -1:
		if k == 0 or k == n:
			cdp[n][k] = 1
		else:
			cdp[n][k] = binomCoeff(n-1,k-1) + binomCoeff(n-1, k)
	return cdp[n][k]

def kterm(a, b, n, k):
	coeff = binomCoeff(n, k)
	if coeff > 1:
		print("{}*".format(coeff), end='')
	if n-k > 0:
		print("{}".format(a), end='')
	if n-k > 1:
		print("^{}".format(n-k), end='')
	if k > 0:
		if n-k == 0:
			print("{}".format(b), end='')
		else:
			print("*{}".format(b), end='')
	if k > 1:
		print("^{}".format(k), end='')

t = int(input())
for _ in range(t):
	inp = input().strip()
	inpList = inp.split('+')
	inpList[0] = inpList[0][1:]
	tmp = inpList[1]
	inpList[1] = tmp.split(')')[0]
	inpList.append(tmp.split(')')[1])
	inpList[2] = int(inpList[2][1:])
	print("Case {}: ".format(_+1), end='')
	for k in range(0,inpList[2]+1):
		kterm(inpList[0],inpList[1],inpList[2],k)
		if k < inpList[2]:
			print('+',end='')
	print()
