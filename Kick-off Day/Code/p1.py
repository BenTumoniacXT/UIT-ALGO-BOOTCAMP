dat = []

def bin_scan(s):
    ss = int(len(s))
    lf = 0
    rg = int(len(dat)) - 1

    while lf <= rg:
        md = int((lf + rg) / 2)
        if dat[md][0:ss] == s: return True

        if dat[md][0:ss] < s: lf = md + 1
        else: rg = md - 1

    return False

n, m, q = map(int, input().split())
a = []
for i in range (n): 
    xs = str(input())
    a.append(xs) 

for i in range (n):
    for j in range (m):
        tmp = a[i][j:j + 10]
        while int(len(tmp)) < 10: tmp = tmp + "*"
        dat.append(tmp)

for j in range (m):
    for i in range (n):
        tmp = ""
        for t in range (10):
            if i + t < n: tmp = tmp + a[i + t][j]
            else: tmp = tmp + "*"

            dat.append(tmp)

dat.sort()

for i in range (q):
    s = str(input())
    if bin_scan(s): print("1", end = "")
    else: print("0", end = "")