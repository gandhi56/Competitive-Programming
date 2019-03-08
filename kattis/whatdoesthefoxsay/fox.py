t = int(input())
for _ in range(t):
	s = input().split()
	n = dict()
	while True:
		an = input().strip()
		if an == "what does the fox say?":
			break
		tmp = an.split("goes")
		n[tmp[0]] = tmp[1][1:]

	for w in s:
		if w not in n.values():
			print(w, end=" ")
	print()
