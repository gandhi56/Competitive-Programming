
def val(x):
    return abs( x - int(str(x)[::-1]) )

i, j, k = map(int, input().split())
cnt = 0
for x in range(i, j+1):
    if val(x) % k == 0:
        cnt += 1
print(cnt)
