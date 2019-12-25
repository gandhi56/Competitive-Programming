
n, m = map(int, input().split())

alpha = 'abcdefghijklmnopqrstuvwxyz'
essay = list()

def main():
	count = 0
	for a in alpha:
		for b in alpha:
			for c in alpha:
				for d in alpha:
					print(a+b+c+d, end=' ')
					count += 1
					if count >= max(n, m//2+1):
						print()
						return

main()
