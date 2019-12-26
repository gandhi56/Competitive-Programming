
def solve(count, memo = None):
	if memo is None:
		memo = {}

	if count in memo.keys():
		return memo[count]

	minValue = min(count)
	solved = True
	for i in range(len(count)):
		count[i] -= minValue
		if count[i] > 0:
			solved = False

	if solved:
		memo[count] = 0

	memo[count] = 99999
	for i in range(len(count)):
		if count[i] - 5 >= 0:
			count[i] -=5
			memo[count] = min(val, 1 + solve(count, memo))
			count[i] += 5
			
		if count[i] - 1 >= 0:
			count[i] -= 1
			memo[count] = min(val, 1 + solve(count, memo))
			count[i] += 1

		if count[i] - 2 >= 0:
			count[i] -= 2
			memo[count] = min(val, 1 + solve(count, memo))
			count[i] += 2

	return memo[count]

t = int(input())

for _ in range(t):
	n = int(input())
	count = [int(s) for s in input().split()]
	print(solve(count))
