n = int(input())
a = list(map(int, input().split()))
ept = []

def calc():
    t = int(0)
    for i in range (n): t += a[i]
    if t % 2 == 1: return ept

    while True:
        detect = int(0)
        for i in range (n): detect += (1 if a[i] % 2 == 0 else 0)

        if detect != n: break

        for i in range (n): a[i] /= 2

        t /= 2

    dp = [False for i in range (int(t + 1))]
    dp[0] = True
    for i in range (n):
        for j in range (int(t - a[i]), -1, -1):
            if dp[j] == True: dp[int(j + a[i])] = True

    if t % 2 != 0 or not dp[int(t / 2)]: return ept
    
    for i in range (n):
        if a[i] % 2 != 0:
            xz = [i + 1]
            return xz

    return ept

core = calc()
print(len(core))
for i in core: print(i, end = " ")