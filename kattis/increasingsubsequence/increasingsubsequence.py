from sys import stdin

def lis(arr):
  l = [[] for i in range(len(arr))]
  for i in range(1, len(arr)):
    for j in range(i):
      if arr[i] > arr[j] and len(l[i]) < len(l[j]) + 1:
        l[i] = l[j][:]
    l[i].append(arr[i])

  k = 0
  for kk in range(len(l)):
    if len(l[kk]) > len(l[k]):
      k = kk
    elif len(l[kk]) == len(l[k]) and sum(l[kk]) < sum(l[k]):
      k = kk

  print(len(l[k]), end=' ')
  print(' '.join([str(x) for x in l[k]]))

for line in stdin:
  arr = [int(s) for s in line.split()]
  if len(arr) == 1 and arr[0] == 0:
    break
  lis(arr)