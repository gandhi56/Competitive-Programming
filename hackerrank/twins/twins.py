from math import floor

def count_twins(n, m):

	# segmented sieve ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	# use simple sieve to compute primes upto sqrt(m)
	isprime = [True] * (m+1)
	isprime[0] = isprime[1] = False

	d = 2
	while d*d <= m:
		if isprime[d]:
			i = 2
			while i*d <= m:
				isprime[i*d] = False
				i += 1
		d += 1

	lo = floor(m**0.5) + 1
	hi = 2 * (floor(m**0.5) + 1)

	while lo < m:
		if hi >= n:
			hi = n



	# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	count = 0

	for i in range(n, m-1):
		if isprime[i] and isprime[i+2]:
			count += 1

	return count

def main():
	n, m = map(int, input().split())
	print(count_twins(n, m))

main()
