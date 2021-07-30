def direct_range(px, p):
    return int(abs(px[0] - p[0])) + int(abs(px[1] - p[1])) - 1

def proc():
    inp = []
    inp = tuple(map(int, input().split()))
    
    sz = (inp[0], inp[1])
    pp = (inp[2], inp[3])
    b1 = (1, 1)
    b2 = (1, 1)

    if direct_range(b1, pp) < direct_range((sz[0], 1), pp): b1 = (sz[0], 1)
    if direct_range(b1, pp) < direct_range((sz[0], sz[1]), pp): b1 = (sz[0], sz[1])
    if direct_range(b1, pp) < direct_range((1, sz[1]), pp): b1 = (1, sz[1])
    
    if direct_range(b1, b2) + direct_range(b2, pp) < direct_range(b1, (sz[0], 1)) + direct_range((sz[0], 1), pp): b2 = (sz[0], 1)
    if direct_range(b1, b2) + direct_range(b2, pp) < direct_range(b1, (sz[0], sz[1])) + direct_range((sz[0], sz[1]), pp): b2 = (sz[0], sz[1])
    if direct_range(b1, b2) + direct_range(b2, pp) < direct_range(b1, (1, sz[1])) + direct_range((1, sz[1]), pp): b2 = (1, sz[1])

    print(b1[0], b1[1], b2[0], b2[1])

t = int(input())
for z in range(t): proc()