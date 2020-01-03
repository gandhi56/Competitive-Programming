t = int(input())

def f(a, b, c):
	if a + b == c:
		return True
	if a - b == c:
		return True
	if a * b == c:
		return True
	if a / b == c:
		return True

for _ in range(t):
	a, b, c = map(int, input().split())

	if a+b==c or a-b==c or b-a==c or a*b==c or a*c==b or b*c==a:
		print("Possible")
	else:
		print("Impossible")
