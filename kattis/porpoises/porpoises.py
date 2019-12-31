import math

fib = {}

def f(n):
	if n in fib:
		return fib[n]

	if n == 0:
		fib[n] = 0
	elif n <= 2:
		fib[n] = 1
	else:
		if n%2 == 0:
			k = n // 2
			val = f(k)
			fib[n] = (val * (val + 2 * f(k-1)))%1000000000
		else:
			k = (n+1)//2
			fib[n] = f(k)**2 + f(k-1)**2
			fib[n] %= 1000000000
	return fib[n]


t = int(input())
for _ in range(t):
	tt, n = map(int, input().split())
	print('{} {}'.format(tt, f(n)))
