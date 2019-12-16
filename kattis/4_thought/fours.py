
# /* Kattis problem: 4-thought
#  *
#  * Topic: Data Structures
#  *
#  * Level: simple
#  * 
#  * Brief problem description: 
#		Given an integer n, print an expression of the form:
# 			4 # 4 # 4 # 4 = n
# 		if each # can be replaced by one of the arithmetic
# 		operations and n can be obtained. If no such expression
# 		exists, print 'no solution'.
# 
#  * Solution Summary:
# 		Take advantage of Python3 dictionary and store all solutions.
# 		There are only 64 possible solutions.
#  *
#  * Used Resources:
#  *	None
#  *
#  * I hereby certify that I have produced the following solution myself
#  * using only the resources listed above in accordance with the CMPUT
#  * 403 collaboration policy.
#  *
#  *
# 		Anshil Gandhi
#  */


import sys

res = {}
res[4 / 4 / 4 / 4] = '4 / 4 / 4 / 4'
res[4 / 4 / 4 * 4] = '4 / 4 / 4 * 4'
res[4 / 4 / 4 - 4] = '4 / 4 / 4 - 4'
res[4 / 4 / 4 + 4] = '4 / 4 / 4 + 4'
res[4 / 4 * 4 / 4] = '4 / 4 * 4 / 4'
res[4 / 4 * 4 * 4] = '4 / 4 * 4 * 4'
res[4 / 4 * 4 - 4] = '4 / 4 * 4 - 4'
res[4 / 4 * 4 + 4] = '4 / 4 * 4 + 4'
res[4 / 4 - 4 / 4] = '4 / 4 - 4 / 4'
res[4 / 4 - 4 * 4] = '4 / 4 - 4 * 4'
res[4 / 4 - 4 - 4] = '4 / 4 - 4 - 4'
res[4 / 4 - 4 + 4] = '4 / 4 - 4 + 4'
res[4 / 4 + 4 / 4] = '4 / 4 + 4 / 4'
res[4 / 4 + 4 * 4] = '4 / 4 + 4 * 4'
res[4 / 4 + 4 - 4] = '4 / 4 + 4 - 4'
res[4 / 4 + 4 + 4] = '4 / 4 + 4 + 4'

res[4 * 4 / 4 / 4] = '4 * 4 / 4 / 4'
res[4 * 4 / 4 * 4] = '4 * 4 / 4 * 4'
res[4 * 4 / 4 - 4] = '4 * 4 / 4 - 4'
res[4 * 4 / 4 + 4] = '4 * 4 / 4 + 4'
res[4 * 4 * 4 / 4] = '4 * 4 * 4 / 4'
res[4 * 4 * 4 * 4] = '4 * 4 * 4 * 4'
res[4 * 4 * 4 - 4] = '4 * 4 * 4 - 4'
res[4 * 4 * 4 + 4] = '4 * 4 * 4 + 4'
res[4 * 4 - 4 / 4] = '4 * 4 - 4 / 4'
res[4 * 4 - 4 * 4] = '4 * 4 - 4 * 4'
res[4 * 4 - 4 - 4] = '4 * 4 - 4 - 4'
res[4 * 4 - 4 + 4] = '4 * 4 - 4 + 4'
res[4 * 4 + 4 / 4] = '4 * 4 + 4 / 4'
res[4 * 4 + 4 * 4] = '4 * 4 + 4 * 4'
res[4 * 4 + 4 - 4] = '4 * 4 + 4 - 4'
res[4 * 4 + 4 + 4] = '4 * 4 + 4 + 4'

res[4 - 4 / 4 / 4] = '4 - 4 / 4 / 4'
res[4 - 4 / 4 * 4] = '4 - 4 / 4 * 4'
res[4 - 4 / 4 - 4] = '4 - 4 / 4 - 4'
res[4 - 4 / 4 + 4] = '4 - 4 / 4 + 4'
res[4 - 4 * 4 / 4] = '4 - 4 * 4 / 4'
res[4 - 4 * 4 * 4] = '4 - 4 * 4 * 4'
res[4 - 4 * 4 - 4] = '4 - 4 * 4 - 4'
res[4 - 4 * 4 + 4] = '4 - 4 * 4 + 4'
res[4 - 4 - 4 / 4] = '4 - 4 - 4 / 4'
res[4 - 4 - 4 * 4] = '4 - 4 - 4 * 4'
res[4 - 4 - 4 - 4] = '4 - 4 - 4 - 4'
res[4 - 4 - 4 + 4] = '4 - 4 - 4 + 4'
res[4 - 4 + 4 / 4] = '4 - 4 + 4 / 4'
res[4 - 4 + 4 * 4] = '4 - 4 + 4 * 4'
res[4 - 4 + 4 - 4] = '4 - 4 + 4 - 4'
res[4 - 4 + 4 + 4] = '4 - 4 + 4 + 4'

res[4 + 4 / 4 / 4] = '4 + 4 / 4 / 4'
res[4 + 4 / 4 * 4] = '4 + 4 / 4 * 4'
res[4 + 4 / 4 - 4] = '4 + 4 / 4 - 4'
res[4 + 4 / 4 + 4] = '4 + 4 / 4 + 4'
res[4 + 4 * 4 / 4] = '4 + 4 * 4 / 4'
res[4 + 4 * 4 * 4] = '4 + 4 * 4 * 4'
res[4 + 4 * 4 - 4] = '4 + 4 * 4 - 4'
res[4 + 4 * 4 + 4] = '4 + 4 * 4 + 4'
res[4 + 4 - 4 / 4] = '4 + 4 - 4 / 4'
res[4 + 4 - 4 * 4] = '4 + 4 - 4 * 4'
res[4 + 4 - 4 - 4] = '4 + 4 - 4 - 4'
res[4 + 4 - 4 + 4] = '4 + 4 - 4 + 4'
res[4 + 4 + 4 / 4] = '4 + 4 + 4 / 4'
res[4 + 4 + 4 * 4] = '4 + 4 + 4 * 4'
res[4 + 4 + 4 - 4] = '4 + 4 + 4 - 4'
res[4 + 4 + 4 + 4] = '4 + 4 + 4 + 4'

m = int(input())

for n in sys.stdin:
	if float(n) in res.keys():
		print(res[float(n)], "=", int(n))
	else:
		print("no solution")

