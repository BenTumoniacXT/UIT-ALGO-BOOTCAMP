n, q = map(int, input().split())
s = str(input())
a = [0 for i in range (len(s) + 1)]

for i in range (1, len(s) + 1):
    a[i] = a[i - 1] + (ord(s[i - 1]) - 96)

for i in range (q):
    x, y = map(int, input().split())
    print(a[y] - a[x - 1])