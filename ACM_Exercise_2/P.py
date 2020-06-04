t = 0
t = int(input())
for i in range(1, t + 1):
    n = 0
    l = 0
    n, l = map(int, input().split())
    queue = []
    posit = []
    cnt = n
    while cnt:
        tmp = []
        tmp.append(list(input().split()))
        tmp.append(int(tmp[0][1]) if tmp[0][2] == 'L' else l - int(tmp[0][1]))
        tmp.append(0 if tmp[0][2] == 'L' else -1)
        posit.append(tmp.pop(0))
        queue.append(tmp)
        tmp = []
        tmp.append(int(posit[-1][1]))
        tmp.append(posit[-1][0])
        posit.pop()
        posit.append(tmp)
        cnt = cnt - 1
    print("Case #", i, ':', sep = '')
    queue.sort()
    posit.sort()
    for j in queue:
        print(j[0], (posit.pop(j[1]))[1])