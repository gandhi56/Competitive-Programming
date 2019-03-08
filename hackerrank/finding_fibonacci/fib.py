def fib(a, b, n):
	if n == 0:
		return (a, b)
	a, b = fib(a, b, n//2)
	c = a * (b * 2 - a)
	d = a * a + b * b
	if n % 2 == 0:
		return (c, d)
	else:
		return (d, c + d)

t = int(input())
for _ in range(t):
	a, b, n = map(int, input().split())
	print(fib(a, b, n))
