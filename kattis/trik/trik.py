s = [1,0,0]
q = input().strip()
for c in q:
	if c == 'A':
		s[0], s[1] = s[1], s[0]
	elif c == 'B':
		s[1], s[2] = s[2], s[1]
	elif c == 'C':
		s[2], s[0] = s[0], s[2]

print(s.index(1) + 1)
