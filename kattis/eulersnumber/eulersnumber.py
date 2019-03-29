from math import factorial as f
n = int(input())
val = 1
k = 1
for i in range(1, n+1):
	val += k*(1/i)
	k *= (1/max(1,i))
print('%.15f'%(val))
