import math

n, k, x = map(int, input().split())
a = list(map(int, input().split()))

c = d = 0
a.sort()
j = 0
spc = []

for i in range (n - 1):
    if a[i + 1] - a[i] <= x: continue
    else:
        sx = int(math.trunc((a[i + 1] - a[i]) / x))
        if (a[i + 1] - a[i]) % x == 0: sx -= 1
        spc.append(sx)

if not len(spc) == 0:
    spc.sort()
    while k >= spc[j] and j < len(spc):
        k -= spc[j]
        j += 1

    j = len(spc) - j

print(j + 1)