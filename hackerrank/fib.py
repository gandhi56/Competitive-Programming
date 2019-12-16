

def mult(A, B, MOD):
	C = [[0,0],[0,0]]
	for i in range(2):
		for j in range(2):
			for k in range(2):
				C[i][j] += int((A[i][k] * B[k][j]) % MOD)

	return C


def pow(A, n, MOD):
	if (n == 1):
		return A
	R = pow(A, n//2, MOD)
	R = mult(R, R, MOD)
	if (n&1):
		R = mult(R, A, MOD)

	return R

def fib(a, b, n):
	F = [[a, b], 
		 [b, 0]]

	Fn = pow(F, n, 1e9+7)
	return Fn[0][0]

t = int(input())
for _ in range(t):
	a, b, n = map(int, input().split())
	print(fib(a, b, n))
