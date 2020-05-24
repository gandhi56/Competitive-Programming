
def ok(x, y):
  digs = list(str(x)) + list(str(y)) + list(str(x*y))
  if len(digs) != 9:
    return False
  for d in '123456789':
    if d not in digs:
      return False
  return True

ans = 0
for x in range(1, 100000):
  for y in range(1, 10000):
    if ok(x, y):
      print(x, y, x*y)
      ans += x*y

print(ans)