n, q = map(int, input().split())
le = 5e4 + 1
lz = [0 for i in range (int(le * 4))]
info = [[] for i in range (int(le * 4))]

def merge(a, b):
    ans = a + b
    ans.sort(reverse = True)
    while len(ans) > 5: ans.pop()

    return ans

def add(a, v):
    ans = []
    for i in a: ans.append((i[0] + v, i[1]))
    
    return ans

def initialize(i, lf, rg):
    lz[i] = 0
    if lf == rg:
        info[i] = []
        info[i].append((0, lf))
        return

    md = int((lf + rg) / 2)
    initialize(int(i * 2), lf, md)
    initialize(int(i * 2 + 1), md + 1, rg)
    info[i] = merge(info[int(i * 2)], info[int(i * 2 + 1)])

def lazy(i):
    lz[int(i * 2)] += lz[i]
    lz[int(i * 2 + 1)] += lz[i]
    info[int(i * 2)] = add(info[int(i * 2)], lz[i])
    info[int(i * 2 + 1)] = add(info[int(i * 2 + 1)], lz[i])
    lz[i] = 0

def update(i, lf, rg, u, v, dlt):
    if rg < u or lf > v: return
    if u <= lf and rg <= v:
        lz[i] += dlt
        info[i] = add(info[i], dlt) 
        return

    md = int((lf + rg) / 2)
    if lz[i] != 0: lazy(i)
    update(int(i * 2), lf, md, u, v, dlt)
    update(int(i * 2 + 1), md + 1, rg, u, v, dlt)
    info[i] = merge(info[int(i * 2)],info[int(i * 2 + 1)])

initialize(int(1), int(1), n)
for i in range (q):
    cmd = list(map(int, input().split()))
    if cmd[0] == 1: update(1, 1, n, cmd[1], cmd[2], cmd[3])
    else: 
        for i in range (cmd[1]):
            print(info[1][i][1], end = " ")

        print()