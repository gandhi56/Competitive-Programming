n,k = map(int,input().split())
n /= 10**k
n = round(n, 0)
n *= 10**k
print(int(n))
