
def extgcd(a, b):
	if not b:
		return 1, 0, a
	s,r,d = extgcd(b, a%b)
	return r, s-r*(a//b), d	

while True:
	n, t = map(int, input().split())
	if n == 0 and t == 0:
		break

	for _ in range(t):
		a, op, b = map(str, input().split())
		a, b = int(a), int(b)
		if op == '+':
			print((a+b)%n)
		elif op == '-':
			print((a-b)%n)
		elif op == '*':
			print((a*b)%n)
		elif op == '/':
			if b == 0:
				print('-1')
			else:
				s, inv, d = extgcd(n, b)
				if d>1:
					print('-1')
				else:
					print((a*inv)%n)
