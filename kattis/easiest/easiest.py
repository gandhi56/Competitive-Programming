from sys import stdin

def digitsum(n):
	tot = 0
	while n:
		tot += n%10
		n //= 10
	return tot

for line in stdin:
	n = int(line.strip())
	if n == 0:
		break
	for p in range(11, 1000000):
		if digitsum(n) == digitsum(n*p):
			print(p)
			break
