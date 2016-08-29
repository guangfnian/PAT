#!/usr/bin/env python3
# -*- coding: utf-8 -*-
def solve(x):
    s, ans = '0123456789ABC', ''
    while x >= 13:
        ans = s[x%13] + ans
        x = x // 13
    ans = s[x] + ans
    while len(ans) < 2:
        ans = '0' + ans
    print(ans, end = '')
print('#', end = '')
for i in input().split():
    solve(int(i))
print('')