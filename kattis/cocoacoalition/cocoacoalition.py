
def factors(n, m, a):
	for x in range(1, n):
		if a%x == 0 and a//x < m:
			return x
	return -1
n, m, a = map(int, input().split())
if a%n==0 or a%m == 0:
	print(1)
else:
	if factors(n, m, a) != -1 or factors(n, m, n*m - a) != -1:
		print(2)
	else:
		print(3)
