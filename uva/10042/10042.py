
def ds(n):
	s = 0
	while n > 0:
		s += n%10
		n //= 10

	return s

def ps(n):
	s = 0
	d = 2
	while d*d <= n:
		while n%d == 0:
			s += ds(d)
			n //= d
		d += 1
	if n > 1:
		s += ds(n)

	if s == n + 1:
		return -1
	else:
		return s

def is_smith(n):
	if ps(n) == -1:
		return False
	else:
		return ps(n) == ds(n)

def solve(n):
	x = n + 1
	while not is_smith(x):
		x += 1

	print(x)

def main():
	t = int(input())
	for _ in range(t):
		n = int(input())

		solve(n)

main()
