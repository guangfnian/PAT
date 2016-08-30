def isPo(x):
    y = x[::-1]
    return x == y


n, k = input().split()
k = int(k)
if isPo(n):
    print(n)
    print(0)
    exit()
for i in range(1,k+1):
    a = int(n)
    b = int(n[::-1])
    n = str(a+b)
    if isPo(n):
        print(n)
        print(i)
        exit()
print(n)
print(k)
