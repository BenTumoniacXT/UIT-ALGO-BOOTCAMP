import math
d, a1, a2, v, t = map(float, input().split())

rs = float(0)
a = float(1) / (a1 * 2) + float(1) / (a2 * 2)
v2 = (-t + math.sqrt(t * t + 4 * a * d)) / (a * 2)

if v2 <= v: rs = v2 / a1 + v2 / a2 + t
else: rs = d / v + v / (2 * a1) + v / (2 * a2)

rs += 5e-14

print(round(rs, 12))