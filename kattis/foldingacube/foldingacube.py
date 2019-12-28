U, D, F, B, L, R = range(6)
rolls = [
            (B, F, U, D, L, R),
            (F, B, D, U, L, R),
            (L, R, F, B, D, U),
            (R, L, F, B, U, D)
        ]
dr = (-1,1,0,0)
dc = (0,0,-1,1)
grid = [input() for i in range(6)]

def ok(r,c):
    return r in range(6) and c in range(6) and grid[r][c] == '#'

def search(r, c, prevR = -1, prevC = -1, face = D):
    if prevR != -1 and prevC != -1 and face == D:
        return False

    for i in range(4):
        rr, cc = r + dr[i], c + dc[i]
        if ok(rr,cc) and (rr, cc) != (prevR, prevC):
            if not search(rr, cc, r, c, rolls[i][face]):
                return False
    return True

def solve():
    for r in range(6):
        for c in range(6):
            if grid[r][c] == '#':
                if not search(r, c):
                    return False
    return True

print('can fold' if solve() else 'cannot fold')

