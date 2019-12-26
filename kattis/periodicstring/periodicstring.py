s = input().strip()

done = False
for k in range(1, len(s)):
	s0 = s[:k]
	i = k
	ok = True
	while i < len(s):
		s1 = s0[-1]+s0[:-1]
		if s1 != s[i:i+k]:
			ok = False
			break
		i += k
		s0 = s1[:]
	
	if ok:
		print(k)
		done = True
		break

if not done:
	print(len(s))
