# /* UVa problem: 401
#  * Topic: String processing
#  *
#  * Level: easy
#  * 
#  * Brief problem description: 
#  *	Given the reversed letter for a subset of every capital letter and the
# 		numbers 1 - 9, for each string s provided in input:
# 			- determine if s is a palindrome
# 			- if every s[i] has a defined reverse and reverse(s) = s_,
# 				where s_ is the string formed by concatenating the reverse
# 				of each character in s.
#  *
#  * Solution Summary:
#  *	- store the reverse of the characters in a dictionary.
# 		- for string s, check if s[i] = s[len(s)-i-1] for all 0 <= i < |s|
# 			to determine if s is a palindrome.
# 		- create s_ and then compare s_ with reverse(s)
#  *
#  * Used Resources:
#  *	None
#  *
#  * I hereby certify that I have produced the following solution myself
#  * using only the resources listed above in accordance with the CMPUT
#  * 403 collaboration policy.
#  *
#  *
#  * --------------------- Anshil Gandhi
#  */




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
