
def longSub(s):
	l = 0
	best = 0
	for i in range(len(s)):
		if i > 1:
			if s[i] != s[i-1]:
				l = 0
		l += 1
		if l > best:
			best = l
	return l

def solve(s):
	p = 0
	best = 0
	for i in range(1, len(s)-1):
		if s.count(s[:i+1]) >= p:
			p = s.count(s[:i+1])
			best = i
		else:
			break
	return best

def main():
	n = int(input())
	input()

	for _ in range(n):
		s = input().strip()
		print(solve(s))
		print()
		input()
main()
