
c = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ_.")


while 1:
	inp = [i for i in input().split()]

	if len(inp) == 1:
		break

	n = int(inp[0])
	s = list(inp[1])

	for i in range(len(s)):
		k = c.index(s[i])
		s[i] = c[(k+n)%len(c)]

	s.reverse()
	print("".join(s))
