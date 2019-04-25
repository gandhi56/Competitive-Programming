import sys

def f(i):
	return (3**(i+1))//(2**i)

t = 1
for n in sys.stdin:
	print('Case {}: {}'.format(t,len(str(f(int(n))) )))
	t += 1
