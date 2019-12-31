from itertools import permutations

MAXN = 10000000
isprime = [True] * MAXN
isprime[0] = isprime[1] = False

for i in range(2, MAXN):
	if isprime[i]:
		j = 2
		while i*j < MAXN:
			isprime[i*j] = False
			j += 1

def list_to_num(numList):
	n = 0
	d = 0
	while d < len(numList):
		n += numList[d] * (10**d)
		d += 1
	return n

def count_primes(n):
	for perm in list(permutations(n)):
		num = list_to_num(perm)
		print(num, isprime[num])

def main():
	t = int(input())
	for _ in range(t):
		num = int(input())

		# generate of list of digits of num
		numList = []
		a = num
		while a:
			numList.append(a%10)
			a //= 10


		count_primes(numList)

main()
