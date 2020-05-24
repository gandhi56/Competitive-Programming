
p = 5

def ok(x):
  xs = list(str(x))
  tot = 0
  for d in xs:
    tot += int(d)**p
  return x == tot

ans = 0
for x in range(10, 10000000):
  if ok(x):
    print(x)
    ans += x

print(ans)