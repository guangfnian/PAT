n = int(input())
cnt, sum = 0, 0
for x in input().split():
    f = 1
    k = 0
    try:
        k = float(x)
    except:
        f = 0
    if f == 0:
        print('ERROR: %s is not a legal number' % x)
        continue
    if k > 1000 or k < -1000:
        print('ERROR: %s is not a legal number' % x)
        continue
    kk = x.split('.')
    if len(kk) == 2 and len(kk[1]) > 2:
        print('ERROR: %s is not a legal number' % x)
        continue
    cnt += 1
    sum += k
if cnt == 0:
    print('The average of 0 numbers is Undefined')
elif cnt == 1:
    print('The average of 1 number is %.2f' % sum)
else:
    print('The average of %d numbers is %.2f' % (cnt, sum/cnt))