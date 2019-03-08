
def solve(s, t, memo = None):
    if s == t:
        return 1
    
    if memo is None:
        memo = list()
        for i in range(len(s)):
            memo.append(list())
            for j in range(len(t)):
                memo[i].append(999999)

    for i in range(len(s)):
        memo[0][i] = 0
        memo[i][0] = 0

    for i in range(len(s)):
        for j in range(len(t)):
            if s[i] == '0':
                s[i] = '1'
                memo[i][j] = 1 + min(memo[i][j], solve(s, t, memo))
                s[i] = '0'
            elif s[i] == '?':
                s[i] = '0'
                memo[i][j] = 1 + min(memo[i][j], solve(s, t, memo))
                s[i] = '?'
            elif s[i] == '?':
                s[i] = '1'
                memo[i][j] = 1 + min(memo[i][j], solve(s, t, memo))
                s[i] = '?'

            for a in range(len(s)):
                for b in range(len(s)):
                    s[a], s[b] = s[b], s[a]
                    memo[i][j] = 1 + min(memo[i][j], 
                        solve(s, t, memo))
                    s[a], s[b] = s[b], s[a]

    """

    # s[i] != t[i] here
    if s[i] == '0': # t[i] = '1'
        s[i] = '1'
        count = min(count, 1 + solve(s, t))
        s[i] = '0'

    if s[i] == '?':
        s[i] = '0'
        count = min(count, 1 + solve(s, t))
        s[i] = '1'
        count = min(count, 1 + solve(s, t))

    for i in range(len(s)):
        for j in range(i+1, len(s)):
            s[i], s[j] = s[j], s[i]
            count = min(count, solve(s, t))
            s[i], s[j] = s[j], s[i]

    return count
    """
c = int(input())

for _ in range(c):
    s = input().strip()
    t = input().strip()

    print(solve(list(s), list(t)))

