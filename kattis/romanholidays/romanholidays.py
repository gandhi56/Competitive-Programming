
tr = {1:'I', 2:'II', 3:'III', 4:'IV', 5:'V', 6:'VI', 7:'VII', 8:'VIII', 9:'IX', 10:'X', 20:'XX', 30:'XXX', 40:'XL', 50:'L', 60:'LX', 70:'LXX', 80:'LXXX', 90:'XC', 100:'C', 200:'CC', 300:'CCC', 400:'CD', 500:'D', 600:'DC', 700:'DCC', 800:'DCCC', 900:'CM', 1000:'M'}


def cvt(x):
	# convert base number into roman
	keysList = sorted(tr.keys(), reverse=True)

	num = []
	for k in keysList:
		while x >= k and x >= 0:
			num.append(tr[k])
			x -= k

		if x == 0:
			break
	return ''.join(num)

def main():
	ro = []
	for x in range(1, 1000):
		ro.append(cvt(x))
	ro.sort()
	A, B = [], []
	for r in ro:
		if r[0] < 'V':
			A.append(r)
		else:
			B.append(r)
	A.sort()
	B.sort(reverse=True)
	n = int(raw_input())

	for _ in range(n):
		x = cvt(int(raw_input().strip()))
		m = 0
		for c in x:
			if c != 'M':
				break
			m += 1
		_ = str(x[0:m:])
		s = str(x[m::])
		if (s < "V"):
			if (s == ''):
				print(m*(1+len(A)))
			else:
				print(m*(1+len(A)) + A.index(s)+1)
		else:
			print(-(m*(len(B)) + B.index(s) + 1))
main()
