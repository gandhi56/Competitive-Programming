def powmod(a, b, p):
    res = 1
    while b > 0:
	if b&1:
	    res = (res * a) % p
	    a = (a * a) % p
	    b >>= 1
    return res

def isqr(a, p):
    if p == 2 or not a:
    	return True
    n = (p - 1) // 2
    return powmod(a, n, p) == 1

n = int(input())
for i in range(n):
    a, p = map(int, input().split())
    print ('yes' if isqr(a%p, p) else 'no')
