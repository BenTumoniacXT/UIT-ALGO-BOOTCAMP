def proc():
    #Input elements for each testcases
    n = int(input())
    a = list(map(int, input().split()))

    #Generate sum of given array
    t = 0
    for i in a: t += i

    #Final solve
    if t == n: print("0")
    elif t < n: print("1")
    else: print(t - n)

#First input
t = int(input())
for z in range(t): proc()