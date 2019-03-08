n = int(input())
for _ in range(n):
	s = input().strip()
	if "simon says" in s:
		print(s[s.find("simon says") + len("simon says") + 1:])
	else:
		print()
