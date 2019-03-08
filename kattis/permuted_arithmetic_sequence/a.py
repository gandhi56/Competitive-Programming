t = int(input())
for _ in range(t):
	inp = [int(i) for i in input().split()]
	n = inp[0]
	numList = inp[1:]

	# is it arithmetic?
	ans = "arithmetic"
	d = numList[1] - numList[0]
	for i in range(1, n-1):
		if numList[i] + d != numList[i+1]:
			ans = "not arithmetic"

	if ans == "arithmetic":
		print(ans)
	else:
		numList.sort()

		ans = "permuted arithmetic"
		d = numList[1] - numList[0]
		for i in range(1, n-1):
			if numList[i] + d != numList[i+1]:
				ans = "non-arithmetic"

		print(ans)
	t += 1
