def solve(s, t):
	totaldiff = 0
	ones = 0
	onetozero = 0
	zerotoone = 0
	for i in range(len(s)):
		if s[i] != t[i]:
			totaldiff += 1
		if s[i] == '?' and t[i] == '1':
			ones -= 1
		elif s[i] == '0' and t[i] == '1':
			ones -= 1
			zerotoone += 1
		elif s[i] == '1' and t[i] == '0':
			ones += 1
			onetozero += 1
	if ones > 0:
		return -1
	return totaldiff - min(zerotoone, onetozero)

tt = int(input())
for _ in range(1, tt+1):
	s = list(input().strip())
	t = list(input().strip())

	if len(s) != len(t):
		print('Case {}: -1'.format(_))
	else:
		print('Case {}: {}'.format(_, solve(s, t)))
