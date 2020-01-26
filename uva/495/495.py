from sys import stdin
dp = {0:0, 1:1}
f = lambda i : dp[i] if i in dp else f(i-1)+f(i-2)
print(''.join(['The Fibonacci number for '+i.strip()+' is '+str(f(int(i)))+'\n' for i in stdin]))
