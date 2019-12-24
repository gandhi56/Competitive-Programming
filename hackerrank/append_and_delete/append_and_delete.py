s = input().strip()
t = input().strip()
k = int(input())

l = 0
while l < len(s) and l < len(t):
    l += 1

# l is the length of the longest prefix

if len(s) + len(t) - 2*l > k:
    print('No')
elif (len(s) + len(t) - 2*l) % 2 == k%2:
    print('Yes')
elif len(s) + len(t) - k < 0:
    print('Yes')
else:
    print('No')

