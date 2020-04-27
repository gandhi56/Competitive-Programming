
def ok(x, a, b):
  return ((x % a) % b) != ((x % b) % a)

def solve(a, b, l, r):
  cnt = 0
  for x in range(l, r+1):
    if ok(x, a, b):
      cnt += 1
  return cnt

t = int(input())
for _ in range(t):
  a, b, q = map(int, input().split())
  for i in range(q):
    l, r = map(int, input().split())
    print(solve(a, b, l, r), end=' ')
  print()