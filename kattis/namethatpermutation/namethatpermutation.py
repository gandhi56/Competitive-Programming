from sys import stdin

def rec_unrank_perm(n, k, r, idp, pi):
    if k > 0:
        idp[n-1], idp[r%n] = idp[r%n], idp[n-1]
        idp, pi = rec_unrank_perm(n-1, k-1, r//n, idp, pi)
        pi.append(idp[n-1])
        idp[n-1], idp[r%n] = idp[r%n], idp[n-1]
    return idp, pi

for line in stdin:
    n, k = map(int, line.split())
    idp = [i for i in range(n)]
    pi = []
    print(' '.join([str(i+1) for i in rec_unrank_perm(n, n, k-1, idp, pi)[1]]))
