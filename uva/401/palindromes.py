import sys

rev = {}
for c in list('ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789'):
	rev[c] = None

rev['A'] = 'A'

rev['A'] = 'A'
rev['E'] = '3'
rev['H'] = 'H'
rev['I'] = 'I'
rev['J'] = 'L'
rev['L'] = 'J'
rev['M'] = 'M'
rev['O'] = 'O'
rev['S'] = '2'
rev['T'] = 'T'
rev['U'] = 'U'
rev['V'] = 'V'
rev['W'] = 'W'
rev['X'] = 'X'
rev['Y'] = 'Y'
rev['Z'] = '5'
rev['1'] = '1'
rev['2'] = 'S'
rev['3'] = 'E'
rev['5'] = 'Z'
rev['8'] = '8'

def is_pal(s):
	if len(s) <= 1:
		return True
	for i in range(len(s)//2+1):
		if s[i] != s[len(s)-i-1]:
			return False
	return True

def is_mirror(s):
	s1 = list(s)
	for i in range(len(s1)):
		if s1[i] in rev.keys():
			if rev[s1[i]] is None:
				return False
			s1[i] = rev[s1[i]]
	if ''.join(s1) == s[::-1]:
		return True
	return False


def solve(s):
	pass

def main():
	for line in sys.stdin:
		s = line.strip()
		if len(s) == 0:
			continue
		print(s, '--', end=' ')
		if is_pal(s):
			if is_mirror(s):
				print('is a mirrored palindrome.')
			else:
				print('is a regular palindrome.')
			print()
		else:
			if is_mirror(s):
				print('is a mirrored string.')
			else:
				print('is not a palindrome.')

			print()

main()
