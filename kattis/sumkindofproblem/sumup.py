
def tot(n):
	return (n*(n+1))//2

def even(n):
	s = 0
	for i in range(2, 2*n+1, 2):
		s += i
	return s

def odd(n):
	s = 0
	for i in range(1, 2*n+1, 2):
		s += i
	return s

t = int(input())

for _ in range(t):
	k, n = map(int, input().split())
	print(k, tot(n), n*n, n*(n+1))
