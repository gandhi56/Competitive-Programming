
def solve(s):
	if len(s) == 11 and s[0] == '8':
		return True

	if len(s) < 11:
		return False

	if len(s) > 11:
		i = 0
		while i < len(s):
			if s[i] == '8':
				break
			i += 1

		if len(s)-i >= 11:
			return True
	return False

t = int(input())
for _ in range(t):
	n = int(input())
	s = input()
	print('YES' if solve(s) else 'NO')
