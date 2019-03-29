c, s = input().split()
if c == 'E':
	i = 0
	while i < len(s):
		j = i
		while j < len(s) and s[i] == s[j]:
			j += 1
		print('{0}{1}'.format(s[i], j-i), end='')
		i = j
else:
	for i in range(0, len(s), 2):
		print(s[i]*int(s[i+1]), end='')
