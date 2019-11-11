
faces = dict()
faces["Tetrahedron"] = 4
faces["Cube"] = 6
faces["Octahedron"] = 8
faces["Dodecahedron"] = 12
faces["Icosahedron"] = 20


n = int(input())
cnt = 0
for i in range(n):
    cnt += faces[input().strip()]
print(cnt)
