input()
times = [int(s) for s in input().split()]
tot = sum(times)
maxTime = max(times)
if maxTime > tot - maxTime:
  print(maxTime*2)
else:
  print(tot)