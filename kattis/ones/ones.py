
while True:

	try:
		n = int(input())
		ans = 1
		digits = 1
		while ans:
			ans = (10*ans+1) % n
			digits += 1

		print(digits)

	except EOFError:
		break
