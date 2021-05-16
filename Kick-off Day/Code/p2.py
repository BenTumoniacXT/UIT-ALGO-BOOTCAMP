fail = "NO_SOLUTION"
n, m = map(int, input().split())

z = 0
for i in range (1, n + 1): z += i

if z < m or (z - m) % 2 != 0:
    print(fail)
else:
    z2 = int((z - m) / 2)
    mat = [0 for i in range (z2 + 1)]
    mat[0] = 1
    directory = [0 for i in range (z2 + 1)]

    for i in range (1, n + 1):
        for t in range (z2, i - 1, -1):
            if mat[t] == 0 and mat[t - i] == 1:
                mat[t] = 1
                directory[t] = t - i

    if not mat[z2]: print(fail)
    else:
        fn = [False for i in range (n + 1)]
        z3 = z2
        while z3 != 0:
            fn[z3 - directory[z3]] = True
            z3 = directory[z3]
        
        for i in range (1, n + 1):
            if fn[i] == True: print("-", end = "")
            else: print("+", end = "")