
def solve(s, memo = None):
	if memo is None:
		memo = {}

	if s in memo.keys():
		return memo[s]

	memo[s] = s.count('o')
	for i in range(0, len(s)-2):
		if s[i:i+3] == "oo-":
			s1 = s[:i] + "--o" + s[i+3:]
			memo[s] = min(memo[s], solve(s1))
		elif s[i:i+3] == "-oo":
			s1 = s[:i] + "o--" + s[i+3:]
			memo[s] = min(memo[s], solve(s1))

	return memo[s]

t = int(input())

for _ in range(t):
	state = input().strip()
	print(solve(state))
