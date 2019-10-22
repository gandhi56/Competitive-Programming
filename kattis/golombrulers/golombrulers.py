import sys

def main():
	for line in sys.stdin:
		marks = [int(s) for s in line.split()]
		if len(marks) == 0:
			break
		marks.sort(reverse=True)
		count = {}
		for i in range(1, max(marks)+1):
			count[i] = 0

		done = False
		for i in range(len(marks)):
			for j in range(i+1, len(marks)):
				count[marks[i] - marks[j]] += 1
				if count[marks[i] - marks[j]] > 1:
					print('not a ruler')
					done = True
					break
			if done:
				break

		if not done:
			if 0 in count.values():
				missingNumbers = []
				for k in count:
					if count[k] == 0:
						missingNumbers.append(k)
				print('missing ', end='')
				for x in missingNumbers:
					print(x, end=' ')
				print()

			else:
				print('perfect')

main()
