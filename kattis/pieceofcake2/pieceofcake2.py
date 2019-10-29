n, h, v = map(int, input().split())
print(4*max(v*h, v*(n-h), (n-v)*h, (n-v)*(n-h)))
