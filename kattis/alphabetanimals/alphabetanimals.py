prev = input().strip()
n = int(input())
words = [input() for i in range(n)]
starts = [0] * 256
for word in words:
	starts[ord(word[0])] += 1
res = '?'
for word in words:
	if word[0] == prev[-1]:
		if res == '?':
			res = word
		if starts[ord(word[-1])] - (ord(word[0]) == ord(word[-1])) == 0:
			res = word + '!'
			break

print(res)
