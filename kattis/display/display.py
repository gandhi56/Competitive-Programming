import sys

d = dict()
d['1']     =   ('    +','    |','    |','    +','    |','    |','    +')
d['2']     =   ('+---+','    |','    |','+---+','|    ','|    ','+---+')
d['3']   =   ('+---+','    |','    |','+---+','    |','    |','+---+')
d['4']    =   ('+   +','|   |','|   |','+---+','    |','    |' ,'    +')
d['5']    =   ('+---+','|    ','|    ','+---+','    |','    |','+---+')
d['6']    =   ('+---+','|    ','|    ','+---+','|   |','|   |','+---+')
d['7']   =   ('+---+','    |','    |','    +','    |','    |','    +')
d['8']   =   ('+---+','|   |','|   |','+---+','|   |','|   |','+---+')
d['9']    =   ('+---+','|   |','|   |','+---+','    |','    |','+---+')
d['0']    =   ('+---+','|   |','|   |','+   +','|   |','|   |','+---+')
colon   =   ('     ','     ','  o  ','     ','  o  ','     ','     ')

grid = [[' ' for i in range(29)] for j in range(7)]

def show():
    for row in grid:
        print(''.join(row))

def addDigit(idx, dig):
    for i in range(7):
        for j in range(5):
            grid[i][idx+j] = dig[i][j]

col = 0
for line in sys.stdin:
    grid = [[' ' for i in range(29)] for j in range(7)]
    line = line.strip()
    if line == 'end':
        break
    addDigit(0, d[line[0]])
    addDigit(7, d[line[1]])
    addDigit(12, colon)
    addDigit(17, d[line[3]])
    addDigit(24, d[line[4]])
    show()
    print()
    print()
print('end')

