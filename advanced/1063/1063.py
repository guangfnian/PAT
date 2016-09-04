n = int(input())
s = [set([int(x) for x in input().split()][1:]) for i in range(n)]
m = int(input())
for ii in range(m):
    a, b = [int(x)-1 for x in input().split()]
    c = s[a] | s[b]
    la, lb, lc = len(s[a]), len(s[b]), len(c)
    ans = (la+lb-lc+0.0) / lc * 100.0
    print("%.1f" % ans + '%')