coins = [10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5]
value = 0

def solve(value, memo = dict()):
	
	if memo is None:
		memo = dict()
		memo[0] = 1
	if value in memo:
		return memo[value]

	memo[value] = 0
	for c in coins:
		for i in range(c, value+1):
			memo[value] += solve(i-c, memo)

	return memo[value]

while 1:
	value = float(input().strip())
	if value == 0.00:
		break
	print(solve(int(value*100)))
