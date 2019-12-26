
t = 1
while True:
	s = input().strip()
	if s == "END":
		break
	
	i = 0
	while s[i] != '*':
		i += 1

	j = i+1
	while j < len(s):
		if s[j] == '*':
			break
		j += 1

	count0 = j-i-1

	i = j
	j = i+1
	isEven = True
	while j < len(s):
		if s[j] == '*':
			if j-i-1 != count0:
				isEven = False
				break
			else:
				i = j
				j = i + 1

		else:
			j += 1


	if isEven:
		print(t, "EVEN")
	else:
		print(t, "NOT EVEN")

	t += 1



