t = int(input())
for _ in range(t):
	s = input().strip()
	if "Simon says" in s:
		print(s[s.find("Simon says")+len("Simon says")+1:])
