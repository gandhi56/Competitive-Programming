from math import ceil, log10
phi = (1 + 5**.5) / 2
def dig(n):
    if n == 1:
        return 1
    return ceil((n * log10(phi) - .5 * log10(5))) 

for x in range(2, 10000000000):
    if dig(x) == 1000:
        print(x)
        break