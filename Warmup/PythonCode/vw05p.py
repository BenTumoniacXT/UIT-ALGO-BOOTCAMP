n, m = map(int, input().split())
mat = []
for i in range(n):
    x = list(map(int, input().split()))
    mat.append(x)

m2 = [[0 for i in range(m - 2)] for j in range(n)]
for i in range(0, n):
    m2[i][0] = mat[i][0] + mat[i][1] + mat[i][2]
    for j in range(1, m - 2):
        m2[i][j] = m2[i][j - 1] - mat[i][j - 1] + mat[i][j + 2]

mn = int(2e9)
for i in range(0, n - 2):
    for j in range(0, m - 2):
        mn = min(m2[i][j] + m2[i + 1][j] + m2[i + 2][j], mn)

print(mn)