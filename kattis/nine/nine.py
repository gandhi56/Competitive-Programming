
p = 1e9+7
pows = [1,9,81,729,6561,59049.531441,4782969,43046721,387420489]

def f(d):
	if d < 10:
		return pows[int(d)]
	tmp = f(d//2)
	if (d%2 == 0):
		return (tmp*tmp)%p
	return (9*tmp*tmp) % p

t = int(input())
for _ in range(t):
	n = int(input())
	ans = 8
	n %= (p - 1)
	ans = (ans * f(n-1)) % p
	print(ans)
