
f = dict()
f[0] = 0
f[1] = 1
p = 2
def fib(j):
	if j in f:
		return f[j]
	for i in range(j+1):
		f[i] = f[i-1] + f[i-2]
	return f[j]

def g(k, n):
	print(k, n)
	if k == 1:
		return fib(n) % p
	return g(1, g(k-1, n)) % p

t = int(input())
for _ in range(t):
	n, k, p = map(int, input().split())
	print(g(k, n))
