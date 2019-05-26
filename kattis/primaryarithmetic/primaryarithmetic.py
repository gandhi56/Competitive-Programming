import sys

for line in sys.stdin:
	a, b = map(str, line.split())
	if a == '0' and b == '0':
		break

	if len(a) < len(b):
		a, b = b, a
	
	while len(b) != len(a):
		b = '0' + b

	a = '0'+a
	b = '0'+b

	a = list(a)
	b = list(b)
	for i in range(len(a)):
		a[i] = int(a[i])

	for i in range(len(b)):
		b[i] = int(b[i])
	
	count = 0
	carry = 0
	for i in range(len(a)-1, -1, -1):
		c = a[i] + b[i] + carry
		carry = c // 10
		if carry > 0:
			count += 1
	if count == 0:
		print('No carry operation.')
	elif count == 1:
		print('1 carry operation.')
	else:
		print('{} carry operations.'.format(count))
