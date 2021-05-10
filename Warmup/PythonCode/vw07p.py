n, m = map(int, input().split())
a = list(map(int, input().split()))

ax = []
ax.append(a[0])
for i in range(1, n):
    ax.append(ax[i - 1] + a[i])

vtm = [int(1e7) for i in range(m)]
vtm.append(0)
for i in range(n, 0, -1):
    for j in range(m, -1, -1):
        if vtm[j] == int(1e7) or j - ax[i - 1] < 0: continue
        vtm[j - ax[i - 1]] = min(vtm[j - ax[i - 1]], vtm[j] + i + 1)

overtime = ax[n - 1] - ax[n - 2]
for i in range(m, -1, -1):
    if vtm[i] == int(1e7): continue
    if j - ax[n - 1] >= 0 and (j - ax[n - 1]) % overtime == 0:
        vtm[0] = min(vtm[0], vtm[j] + n + 1 + (j - ax[n - 1]) / overtime)

if vtm[0] == int(1e7): print("-1")
else: print(vtm[0] - 1)